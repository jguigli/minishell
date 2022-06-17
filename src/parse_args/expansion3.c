#include "../../includes/minishell.h"

char	*manage_dquote(char *data, char **env, int *i, char *str)
{
	(*i)++;			
	while (data[*i] != 34 && data[*i])
	{
		str = case_no$_quote(data, i, str);
		if (data[*i] == '$' && data[*i + 1] == '{')
			str = case_$bracket_quote(data, env, i, str);
		else if (data[*i] == '$' && data[*i + 1] != '{')
			str = case_$_quote(data, env, i, str);
	}
	return (str);
}

char	*case_no$_quote(char *data, int *i, char *str)
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

char	*case_$_quote(char *data, char **env, int *i, char *str)
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
	{
        str = ft_strjoin(str, temp);
	}
	return (str);	
}

char	*case_$bracket_quote(char *data, char **env, int *i, char *str)
{
	char	*temp;
	int		j;

    (*i) += 2;
    j = *i;
    while (data[*i] != '}' && data[*i])
        (*i)++;
    temp = ft_substr(data, j, *i - j);
    temp = search_in_env_var(temp, env);
    if (temp)
        str = ft_strjoin(str, temp);
    (*i)++;
	return (str);
}