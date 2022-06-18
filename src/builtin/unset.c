#include "../../includes/minishell.h"

static char	**unset_var(int position, char **env)
{
	size_t		i;
	char		**tab;

	i = position;
	tab = dup_env_tab(env);
	while (i < ft_strlen_double(tab) - 1)
	{
		tab[i] = ft_strdup(tab[i + 1]);
		i++;
	}
	tab[i] = 0;
	free_char_tab(env);
	return (tab);
}

void	ft_unset(char **arg, t_main *main)
{
	size_t		i;
	size_t		j;
	size_t		z;

	i = 1;
	if (!arg || !main->env)
		return ;
	while (arg[i])
	{
		j = 0;
		while (main->env[j])
		{
			z = 0;
			while (main->env[j][z] != '=')
				z++;
			if (z == ft_strlen(arg[i]))
			{
				if (!ft_strncmp(arg[i], main->env[j], z))
					main->env = unset_var(j, main->env);
			}
			j++;
		}
		i++;
	}
}
