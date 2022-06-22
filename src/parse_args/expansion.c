#include "../../includes/minishell.h"

void	delete_nodes_after_expansion(t_dblist *list)
{
	t_datas		*stock_prev;
	t_datas		*stock_next;
	t_datas		*stock_curr;
	t_datas		*current;

	current = list->first;
	while(current && current->data[0] == '\0')
	{
		stock_curr = current;
		current = current->next;
		free(stock_curr);
	}
	//printf("dataaaaa : %s\n", current->data);
	list->first = current;
	current = current->next;
	while(current)
	{
		if (current && current->data[0] != '\0')
			current = current->next;
		else if	(current && current->data[0] == '\0')
		{
			//printf("icii vide ? %s\n", current->data);
			if (current->next)
			{
				stock_next = current->next;
				stock_curr = current;
				stock_prev = current->previous;
				current = current->next;
				free (stock_curr);
				stock_prev->next = stock_next;
				stock_next->previous = stock_prev;
			}
			else if (current->next == NULL)
			{
				stock_prev = current->previous;
				stock_prev->next = NULL;
				free (current);
				break ;
			}
		}
	}
}

static void	manage_expansion(t_datas *list, char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (list->data[i])
	{
		str = case_nodol_noquote(list->data, &i, str);
		if (list->data[i] == '$' && list->data[i + 1] == '?')
			str = case_status(&i, str);
		else if (list->data[i] == '$' && list->data[i + 1] == '\0')
			str = case_dolafterdol(&i, str);
		else if (list->data[i] == '$')
			str = case_dol_noquote(list->data, env, &i, str);
		else if (list->data[i] == 34)
			str = manage_dquote(list->data, env, &i, str);
		else if (list->data[i] == 39)
			str = case_single_quote(list->data, &i, str);
		if (list->data[i] != '\0')
			i++;
	}
	free(list->data);
	list->data = str;
}

void	shell_parameter_expansion(t_dblist *gr_list, char **env)
{
	t_datas	*list;

	list = gr_list->first;
	//affiche(gr_list);
	while (list)
	{
		if (list->type == 39)
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		else
			manage_expansion(list, env);
		//free(str); Vu Joel et Amina : ok pour enlever pour les noeuds.
		if (list->next)
			list = list->next;
		else
			break ;
	}
	affiche(gr_list);
}