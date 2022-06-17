#include "../../includes/minishell.h"

char	*manage_dquote(char *data, char **env, int *i, char *str)
{
	(*i)++;			
	while (data[*i] != 34 && data[*i])
	{
		str = case_nodol_quote(data, i, str);
		if (data[*i] == '$')
			str = case_dol_quote(data, env, i, str);
	}
	return (str);
}

char	*case_nodol_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

    j = *i;
    while (data[*i] != '$' && data[*i] != 34 && data[*i])
        (*i)++;
    if (*i != j)
    {					
        temp = ft_substr(data, j, *i - j);
        str = ft_strjoin(str, temp);
    }
	return (str);
}

char	*case_dol_quote(char *data, char **env, int *i, char *str)
{
	char	*temp;
	int		j;

    (*i)++;
    j = *i;
    if (!ft_isalnum(data[*i]))
        str = ft_strjoin(str, "$");
    while (ft_isalnum(data[*i]) && data[*i])
        (*i)++;
    temp = ft_substr(data, j, *i - j);
    temp = search_in_env_var(temp, env);
    if (temp)
        str = ft_strjoin(str, temp);
    (*i)--;
	return (str);	
}
