#include "../../../includes/minishell.h"

char	**dup_env_tab(char **env)
{
	int	i;
	char	**tab;

	i = 0;
	while (env[i])
		i++;
	tab = (char**)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**env_sorted_export(char **env)
{
	int	i;
	int	j;
	char	**tab;
	char	*temp;

	i = 0;
	tab = dup_env_tab(env);
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void    print_export(char **env)
{
	int	i;
	int	j;
	char	**tab;

	i = 0;
	tab = env_sorted_export(env);
	if (!tab)
		exit(0);
	while (tab[i])
	{
		j = 0;
		printf("declare -x ");
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			if (tab[i][j] == '=')
				printf("\"");
			j++;
		}
		printf("\"\n");
		i++;
	}
	while (tab[i])
		free(tab[i++]);
	free(tab);
}