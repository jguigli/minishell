#include "../../includes/minishell.h"

void	shell_parameter_expansion(t_dblist *gr_list, char **env)
{
	t_datas	*list;
	int		i;
	char	*str;

	list = gr_list->first;
	//affiche(gr_list);
	while (list)
	{
		i = 0;
		//printf("herrrrre 1 -- %s\n", list->data);
		if (list->type == 39)
		{
			//printf("herrrrre 2 -- %s\n", list->data);
			if (list->next)
				list = list->next;
			else
				break ;
			//printf("herrrrre 3 -- %s\n", list->data);
			//printf("herrrrre 4 -- %d\n", list->previous->type);
		}
		else
		{
			str = ft_strdup("");
			while (list->data[i])
			{
				str = case_no$_noquote(list->data, &i, str);
				if (list->data[i] == '$' && list->data[i + 1] == '?')
				{
					str = ft_strjoin(str, ft_itoa(g.status)); // PAS SUR
					i += 1;
				}
				else if (list->data[i] == '$' && list->data[i + 1] != '{')
					str = case_$_noquote(list->data, env, &i, str);
				else if (list->data[i] == '$' && list->data[i + 1] == '{')
					str = case_$bracket_noquote(list->data, env, &i, str);
				else if (list->data[i] == 34)
					str = manage_dquote(list->data, env, &i, str);
				else if (list->data[i] == 39)
					str = case_single_quote(list->data, &i, str);	
				if (list->data[i] == '\0')
					break ;
				else
					i++;
			}
			free(list->data); //modifie par amina (remonte dans le while)
			list->data = ft_strdup(str); //modifie par amina (idem)
		}
		if (list->next)
			list = list->next;
		else
			break ;
		//printf("list data apres next == %s\n", list->data);
		//free(str); //commente par Amina
	}
	//affiche(gr_list);
}