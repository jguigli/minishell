#include "../../includes/minishell.h"

char	*search_in_env_var(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !*env)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		// printf("j = %d --- env[i] = %s\n", j, env[i]);
		// printf("str = %s length == %ld\n", str, ft_strlen(str));
		if (j == ft_strlen(str))
		{
			// printf("ici 1%s\n", str);
			if (!ft_strncmp(str, env[i], j))
			{
				// printf("ici 2%s\n", str);
				return (free(str), &env[i][j + 1]);
			}
		}
		// if (!ft_strncmp(str, env[i], j))
		// 	return (free(str), &env[i][j + 1]);
		i++;
	}
	return (free(str), NULL);
}

void	shell_parameter_expansion(t_dblist *gr_list, char **env)  // $USER$USER marche quand y a plus le i++ de la boucle principale mais ec""ho -n "${USER}" fonctionne plus
{
	t_datas	*list;
	int		i;
	int		j;
	char	*str;
	char	*temp;

	list = gr_list->first;
	// str = ft_strdup("");
	while (list)
	{
		i = 0;
		str = ft_strdup("");
		while (list->data[i])
		{
			j = i;
			while (list->data[i] != '$' && list->data[i] != 34 && list->data[i] != 39 && list->data[i])
				i++;
			if (i != j)
			{
				temp = ft_substr(list->data, j, i - j);
				str = ft_strjoin(str, temp);
			}
			if (list->data[i] == '$' && list->data[i + 1] != '{')
			{
				i++;
				j = i;
				while (ft_isalnum(list->data[i]) && list->data[i]) // prb avec les othersymbols
					i++;
				temp = ft_substr(list->data, j, i - j);
				//printf("hello =%s\n", temp);
				temp = search_in_env_var(temp, env);
				//printf("%s\n", temp);
				if (temp)
					str = ft_strjoin(str, temp);
				i--;
			}
			else if (list->data[i] == '$' && list->data[i + 1] == '{')
			{
				i += 2;
				j = i;
				while (list->data[i] != '}' && list->data[i])
					i++;
				temp = ft_substr(list->data, j, i - j);
				temp = search_in_env_var(temp, env);
				if (temp)
					str = ft_strjoin(str, temp);
			}
			else if (list->data[i] == 34)
			{	
				i++;			
				while (list->data[i] != 34 && list->data[i])
				{
					j = i;
					while (list->data[i] != '$' && list->data[i] != 34 && list->data[i])
						i++;
					if (i != j)
					{					
						temp = ft_substr(list->data, j, i - j);
						str = ft_strjoin(str, temp);
					}
					if (list->data[i] == '\0')
						break ;
					if (list->data[i] == '$' && list->data[i + 1] == '{')
					{
						i += 2;
						j = i;
						while (list->data[i] != '}' && list->data[i])
							i++;
						temp = ft_substr(list->data, j, i - j);
						temp = search_in_env_var(temp, env);
						if (temp)
							str = ft_strjoin(str, temp);
						i++;
					}
					else if (list->data[i] == '$' && list->data[i + 1] != '{')
					{
						i++;
						j = i;
						while (ft_isalnum(list->data[i]) && list->data[i]) // prb avec les othersymbols
							i++;
						temp = ft_substr(list->data, j, i - j);
						temp = search_in_env_var(temp, env);
						if (temp)
							str = ft_strjoin(str, temp);
					}
				}
			}
			else if (list->data[i] == 39)
			{
				i++;
				if (list->data[i] != 39 && list->data[i])
				{
					j = i;
					while (list->data[i] != 39 && list->data[i])
						i++;
					temp = ft_substr(list->data, j, i - j);
					str = ft_strjoin(str, temp);
				}
			}
			i++;
		}
		free(list->data);
		list->data = ft_strdup(str);
		free(str);
		list = list->next;
	}
	affiche(gr_list);
}