#include "../../../includes/minishell.h"

char	**dup_env_tab_export(char **env)
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
	tab[i++] = 0;
	tab[i] = 0;
	return (tab);
}

int		export_appreciate_symbol(char arg)
{
	if (arg == '-' || arg == '+' || arg == '*' || arg == '#' || arg == ':'
		|| arg == '$' || arg == '/' || arg == '\\' || arg == ':'
			|| arg == '=' || arg == '[' || arg == ']' || arg == '{'
				|| arg == '}' || arg == ',')
				return (1);
	return (0);
}

int		check_arg_export(char *arg)
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
	while (arg[i] != '=' && arg[i])
	{
		if (!ft_isalnum(arg[i]))
		{
			printf("minishell: '%s': not a valid identifier\n", arg);
			return (0);
		}
		i++;
	}
	if (arg[i + 1] != '\0')
		i++;
	while (arg[i])
	{
		printf("arg = %c\n", arg[i]);
		if (!ft_isalnum(arg[i]) && !export_appreciate_symbol(arg[i]))
		{
			printf("minishell: '%s': not a valid identifier\n", arg);
			return (0);
		}
		i++;
	}	
	if (!ft_strchr(arg, '='))
		return (0);
	return (1);
}

char	**export_var_env(char *arg, char **env)
{
	int	i;

	i = 0;
	env = dup_env_tab_export(env);
	while (env[i])
		i++;
	env[i] = ft_strdup(arg);
	env[++i] = 0;
	i = 0;
	while (env[i])
		printf("env = %s\n", env[i++]);
	return (env);
}

void    ft_export(char **arg, char **env)
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