#include "../../includes/minishell.h"

char	*case_no$_noquote(char *data, int *i, char *str)
{
	char	*temp;
    char    *rep;
	int		j;

	j = *i;
	//printf(" 11111 ---- data == %s - taille = %zu\n", data, ft_strlen(data));
	while (data[*i] != '$' && data[*i] != 34 && data[*i] != 39 && data[*i])
		(*i)++;
	if (*i != j)
	{
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
		//printf(" 1 ---- str == %s - taille = %zu\n", str, ft_strlen(str));
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
	//printf(" 222 ---- data == %s - taille = %zu\n", data, ft_strlen(data));
    while (ft_isalnum(data[*i]) && data[*i])
        (*i)++;
    temp = ft_substr(data, j, *i - j);
    temp = search_in_env_var(temp, env);
    if (temp)
        str = ft_strjoin(str, temp);
    (*i)--;
	//printf(" 2 ----- str == %s - taille = %zu\n", str, ft_strlen(str));
	return (str);
}

char	*case_$bracket_noquote(char *data, char **env, int *i, char *str)
{
	char	*temp;
	int		j;

    (*i) += 2;
    j = *i;
	//printf(" 33333 ---- data == %s - taille = %zu\n", data, ft_strlen(data));
    while (data[*i] != '}' && data[*i])
        (*i)++;
    temp = ft_substr(data, j, *i - j);
    temp = search_in_env_var(temp, env);
    if (temp)
        str = ft_strjoin(str, temp);
	//printf(" 3 ---- str == %s - taille = %zu\n", str, ft_strlen(str));
	return (str);
}

char	*case_single_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

    (*i)++;
	//printf(" 444 ---- data == %s - taille = %zu\n", data, ft_strlen(data));
    if (data[*i] != 39 && data[*i])
    {
        j = *i;
        while (data[*i] != 39 && data[*i])
            (*i)++;
        temp = ft_substr(data, j, *i - j);
        str = ft_strjoin(str, temp);
    }
	//printf(" 4 ---- str == %s - taille = %zu\n", str, ft_strlen(str));
	return (str);
}