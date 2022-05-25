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