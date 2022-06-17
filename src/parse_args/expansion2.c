#include "../../includes/minishell.h"

char    *case_status(int *i, char *str)
{
	char	*temp;

	temp = ft_itoa(g.status);
	str = ft_strjoin(str, temp);
	free(temp);
	(*i)++;
	return (str);
}

char	*case_dolafterdol(int *i, char *str)
{
	str = ft_strjoin(str, "$");
	(*i)++;
	return (str);
}

char	*case_nodol_noquote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	j = *i;
	while (data[*i] != '$' && data[*i] != 34 && data[*i] != 39 && data[*i])
		(*i)++;
	if (*i != j)
	{
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
        free(temp);
	}
    return (str);
}

char	*case_dol_noquote(char *data, char **env, int *i, char *str)	
{
	char	*temp;
	int		j;

	(*i)++;
    j = *i;
	if (!ft_isalnum(data[*i]) && data[*i] != 34 && data[*i] != 39)
	{
		while (!ft_isalnum(data[*i]) && data[*i] != 34 && data[*i] != 39 && data[*i] != '$')
			(*i)++;
   		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, "$");
        str = ft_strjoin(str, temp);
		return (str);
	}
    while (ft_isalnum(data[*i]) && data[*i])
        (*i)++;
    temp = ft_substr(data, j, *i - j);
    temp = search_in_env_var(temp, env);
    if (temp)
        str = ft_strjoin(str, temp);
    (*i)--;
	return (str);
}

char	*case_single_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

    (*i)++;
    if (data[*i] != 39 && data[*i])
    {
        j = *i;
        while (data[*i] != 39 && data[*i])
            (*i)++;
        temp = ft_substr(data, j, *i - j);
        str = ft_strjoin(str, temp);
    }
	return (str);
}
