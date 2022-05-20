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
		if (!ft_strncmp(str, env[i], j))
			return (free(str), &env[i][j + 1]);
		i++;
	}
	return (NULL);
}

void	shell_parameter_expansion(t_dblist *gr_list, char **env)  // $USER$USER marche quand y a plus le i++ de la boucle principale mais ec""ho -n "${USER}" fonctionne plus
{
	t_datas	*list;
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	list = gr_list->first;
	str = ft_strdup("");
	while (list)
	{
		while (list->data[i])
		{
			printf("LAAAAA\n");
			j = i;
			while (list->data[i] != '$' && list->data[i] != 34 && list->data[i] != 39 && list->data[i])
			{
				printf("ici 1 et char[%d] = %c\n", i, list->data[i]);
				i++;
			}
			if (i != j)
			{
				printf("ici 2\n");
				temp = ft_substr(list->data, j, i - j);
				str = ft_strjoin(str, temp);
				//free(temp);
			}
			if (list->data[i] == '$' && list->data[i + 1] != '{')
			{
				printf("ici 3\n");
				i++;
				j = i;
				while (ft_isalnum(list->data[i]) && list->data[i]) // prb avec les othersymbols
					i++;
				temp = ft_substr(list->data, j, i - j);
				temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
				if (temp)
					str = ft_strjoin(str, temp);
				//free(temp);
			}
			else if (list->data[i] == '$' && list->data[i + 1] == '{')
			{
				printf("ici 4\n");
				i += 2;
				j = i;
				while (list->data[i] != '}' && list->data[i])
					i++;
				if (list->data[i] != '}')
					return ;
				temp = ft_substr(list->data, j, i - j);
				temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
				if (temp)
					str = ft_strjoin(str, temp);
				i++;
				//free(temp);
			}
			else if (list->data[i] == 34)
			{
				printf("ici 5\n");	
				i++;			
				if (list->data[i] != 34 && list->data[i])
				{
					j = i;
					while (list->data[i] != '$' && list->data[i] != 34 && list->data[i])
						i++;
					if (i != j)
					{
					printf("ici 6\n");						
						temp = ft_substr(list->data, j, i - j);
						printf("temp = %s\n", temp);
						str = ft_strjoin(str, temp);
						printf("str = %s\n", str);
						//free(temp);
					}
					if (list->data[i] == '\0')
						break ;
					if (list->data[i] == '$' && list->data[i + 1] == '{')
					{
						i += 2;
						j = i;
						while (list->data[i] != '}' && list->data[i])
							i++;
						if (list->data[i] != '}')
							return ;
						temp = ft_substr(list->data, j, i - j);
						printf("%s\n", temp);
						temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
						if (temp)
							str = ft_strjoin(str, temp);
						i++;
						//free(temp);
					}
					else if (list->data[i] == '$' && list->data[i + 1] != '{')
					{
						i++;
						j = i;
						while (ft_isalnum(list->data[i]) && list->data[i]) // prb avec les othersymbols
							i++;
						temp = ft_substr(list->data, j, i - j);
						printf("%s\n", temp);
						temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
						if (temp)
							str = ft_strjoin(str, temp);
						//free(temp);
					}
					// if (list->data[i] == '\0')
					// 	break ;
				}
				//i--;
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
					//free(temp);
				}
			}
			//i++;
		}
		free(list->data);
		list->data = ft_strdup(str);
		list = list->next;
	}
	affiche(gr_list);
}