#include "../../../includes/minishell.h"

int	export_appreciate_symbol(char arg)
{
	if (arg == '-' || arg == '+' || arg == '*' || arg == '#' || arg == ':'
		|| arg == '$' || arg == '/' || arg == '\\' || arg == ':'
		|| arg == '=' || arg == '[' || arg == ']' || arg == '{'
		|| arg == '}' || arg == ',')
		return (1);
	return (0);
}

char	**dup_env_tab(char **env)
{
	int		i;
	char	**tab;

	i = 0;
	while (env[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
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
	int		i;
	int		j;
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
	free_char_tab(env);
	return (tab);
}

void	print_tab_export(char **tab, int *i, int *j, int *lim)
{
	printf("declare -x ");
	while (tab[*i][*j])
	{
		printf("%c", tab[*i][*j]);
		if (tab[*i][*j] == '=' && *lim == 0)
		{
			printf("\"");
			*lim = 1;
		}
		(*j)++;
	}
	printf("\"\n");
	(*i)++;
}

void	print_export(char **env)
{
	int		i;
	int		j;
	char	**tab;
	int		lim;

	i = 0;
	tab = env_sorted_export(env);
	if (!tab)
		exit(0);
	while (tab[i])
	{
		j = 0;
		lim = 0;
		print_tab_export(tab, &i, &j, &lim);
	}
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
