#include "../../includes/minishell.h"

char	*search_in_env_var(char *str, char **env)
{
	while (ft_strncmp(str, *env, ft_strlen(str)))
		env++;
	return (*env + (ft_strlen(str) + 1));
}

void	shell_parameter_expansion(t_dblist *gr_list, char **env)
{
	t_datas	*list;
	// t_dblist *list;
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	list = gr_list->first;
	printf("%s\n", list->data);
	str = ft_strdup("");
	while (list)
	{
		while (list->data[i])
		{
			printf("LAAAAA\n");
			j = i;
			while (list->data[i] != '$' && list->data[i] != 34 && list->data[i] != 39 && list->data[i])
			{
				printf("ici 1\n");
				i++;
			}
			if (i != j)
			{
				printf("ici 2\n");
				temp = ft_substr(list->data, j, i - j);
				str = ft_strjoin(str, temp);
				free(temp);
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
				str = ft_strjoin(str, temp);
				free(temp);
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
				str = ft_strjoin(str, temp);
				free(temp);
			}
			else if (list->data[i] == 34)
			{
				printf("ici 5\n");				
				while (list->data[i] != 34 && list->data[i])
				{
					j = i;
					while (list->data[i] != '$' && list->data[i])
						i++;
					if (i != j)
					{
					printf("ici 6\n");						
						temp = ft_substr(list->data, j, i - j);
						str = ft_strjoin(str, temp);
						free(temp);
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
						temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
						str = ft_strjoin(str, temp);
						free(temp);
					}
					else if (list->data[i] == '$' && list->data[i + 1] != '{')
					{
						i++;
						j = i;
						while (ft_isalnum(list->data[i]) && list->data[i]) // prb avec les othersymbols
							i++;
						temp = ft_substr(list->data, j, i - j);
						temp = search_in_env_var(temp, env); //=> si trouver on return la var d'env sinon on renvoi rien et on strjoin rien
						str = ft_strjoin(str, temp);
						free(temp);
					}
					if (list->data[i] == '\0')
						break ;
					else
						i++;
				}
				i--;
			}
			else if (list->data[i] == 39)
			{
				j = i;
				i++;
				while (list->data[i] != 39 && list->data[i])
					i++;
				temp = ft_substr(list->data, j, i - j);
				str = ft_strjoin(str, temp);
				//free(temp);
				i--;
			}
			i++;
		}
		free(list->data);
		list->data = ft_strdup(str);
		list = list->next;
	}
	affiche(gr_list);
}