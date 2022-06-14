#include "../../includes/minishell.h"

char	*case_no$_noquote(char *data, int *i, char *str)
{
	char	*temp;
    char    *rep;
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

char	*case_$_noquote(char *data, char **env, int *i, char *str) // RAJOUTER FREE TEMP	
{
	char	*temp;
	int		j;

	(*i)++;
    j = *i;
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