#include "../../includes/minishell.h"

char	*search_in_env_var(char *var, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!var || !*env)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (j == ft_strlen(var))
		{
			if (!ft_strncmp(var, env[i], j))
				return (free(var), &env[i][j + 1]);
		}
		i++;
	}
	return (free(var), NULL);
}

void	set_var_in_env(char *var, char *path, char **env)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	j = 0;
	if (!var || !*env || !path)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (!ft_strncmp(var, env[i], j))
		{
			str = ft_substr(env[i], 0, j + 1);
			str = ft_strjoin(str, path);
			env[i] = ft_strdup(str);
		}
		i++;
	}
	return (free(var), NULL);
}