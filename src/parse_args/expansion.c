#include "../../includes/minishell.h"

void	shell_parameter_expansion(t_dblist *gr_list, char **env)
{
	t_datas	*list;
	int		i;
	char	*str;

	list = gr_list->first;
	affiche(gr_list);
	while (list)
	{
		i = 0;
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
		free(list->data);
		list->data = ft_strdup(str);
		free(str);
		list = list->next;
	}
	//affiche(gr_list);
}