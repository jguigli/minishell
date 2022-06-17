#include "../../includes/minishell.h"

char	**unset_var(int position, char **env)
{
	int		i;
	char	**tab;

	i = position;
	tab = dup_env_tab(env);
	while (i < ft_strlen_double(tab) - 1)
	{
		tab[i] = ft_strdup(tab[i + 1]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	ft_unset(char **arg, char **env)
{
	int		i;
	int		j;
	int		z;

	i = 1;
	if (!arg || !env)
		return (0);
	while (arg[i])
	{
		j = 0;
		while (env[j])
		{
			z = 0;
			while (env[j][z] != '=')
				z++;
			if (z == ft_strlen(arg[i]))
			{
				if (!ft_strncmp(arg[i], env[j], z))
					g.env = unset_var(j, env);
			}
			j++;
		}
		i++;
	}
	return (0);
}
