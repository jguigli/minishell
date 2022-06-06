#include "../../includes/minishell.h"

int	size_of_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**unset_var(int position, char **env)
{
    int	i;
	char **tab;

	i = position;
	tab = dup_env_tab(env);
	printf("position = %d\n", position);
    while (i < size_of_tab(tab) - 1)
	{
		tab[i] = ft_strdup(tab[i + 1]);
		//printf("%s\n", tab[i]);
		i++;
	}
	tab[i] = 0;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i++]);
	}
	return (tab);
}


int    ft_unset(char **arg, char **env)
{
    int	i;
	int	j;
    int z;

	i = 1;
	if (!*arg || !*env)
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