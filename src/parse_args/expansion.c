#include "../../includes/minishell.h"

char	*manage_expansion(t_datas *list, char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (list->data[i])
	{
		str = case_nodol_noquote(list->data, &i, str);
		if (list->data[i] == '$' && list->data[i + 1] == '?')
			str = case_status(list->data, &i, str);
		else if (list->data[i] == '$' && list->data[i + 1] == '\0')
			str = case_dolafterdol(list->data, &i, str);
		else if (list->data[i] == '$')
			str = case_dol_noquote(list->data, env, &i, str);
		else if (list->data[i] == 34)
			str = manage_dquote(list->data, env, &i, str);
		else if (list->data[i] == 39)
			str = case_single_quote(list->data, &i, str);
		if (list->data[i] != '\0')
			i++;
	}
	return (str);	
}

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
		if (list->type == 39)
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		else
			str = manage_expansion(list, env);
		free(list->data);
		list->data = ft_strdup(str);
		free(str);
		list = list->next;
	}
	affiche(gr_list);
}