#include "../../../includes/minishell.h"

char	**dup_env_tab_export(char **env)
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
	tab[i++] = 0;
	tab[i] = 0;
	return (tab);
}

static int	check_each_arg(char *arg, int *i)
{
	int	j;

	j = 0;
	while (arg[*i] != '=' && arg[*i])
	{
		if (!ft_isalnum(arg[*i]))
		{
			printf("minishell: '%s': not a valid identifier\n", arg);
			return (0);
		}
		(*i)++;
	}
	if (arg[*i + 1] != '\0')
		(*i)++;
	while (arg[*i])
	{
		if (!ft_isalnum(arg[*i]) && !export_appreciate_symbol(arg[*i]))
		{
			printf("minishell: '%s': not a valid identifier\n", arg);
			return (0);
		}
		(*i)++;
	}
	return (1);
}

static int	check_arg_export(char *arg)
{
	int	i;
	int	pos;

	i = 1;
	pos = 1;
	if (!ft_isalpha(arg[0]))
	{
		printf("minishell: '%s': not a valid identifier\n", arg);
		return (0);
	}
	check_each_arg(arg, &i);
	if (!ft_strchr(arg, '='))
		return (0);
	return (1);
}

static char	**export_var_env(char *arg, char **env)
{
	int	i;

	i = 0;
	env = dup_env_tab_export(env);
	while (env[i])
		i++;
	env[i] = ft_strdup(arg);
	env[++i] = 0;
	return (env);
}

void	ft_export(char **arg, char **env)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	g.status = 0;
	if (!arg[1])
		print_export(env);
	while (arg[i])
	{
		if (check_arg_export(arg[i]))
			g.env = export_var_env(arg[i], env);
		else
			g.status = 1;
		i++;
	}
}
