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

int		check_arg_export(char **arg)
{
	int	i;
	int	j;
	int	pos;

	i = 1;
	j = 0;
	pos = 1;
	while (ft_strcmp(arg[i], "="))
	{
		j = 1;
		if (!ft_isalpha(arg[i][0]))
			return (0);
		while (arg[i][j])
		{
			if (!ft_isalpha(arg[i][i]) || !ft_isdigit(arg[1][i]))
				return (0);
			j++;
		}
		pos++;
		i++;
	}
	while (arg[++i][j])
	{
		if (!ft_isalpha(arg[1][i]) || !ft_isdigit(arg[1][i]) || !export_appreciate_symbol(arg[i][j]))
			return (0);
		j++;
	}
	if (arg[++i])
		return (0);
	return (pos);
}

char	**export_var_env(char **arg, int pos, char **env)
{
	int	i;

	i = 0;
	env = dup_env_tab_export(env);
	while (env[i])
		i++;
	env[i] = ft_strdup(arg[pos]);
	env[++i] = 0;
}

void    ft_export(char **arg, char **env)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	if (!arg[1])
		print_export(env);
	if (check_arg_export(arg))
	{
		pos = check_arg_export(arg);
		g.env = export_var_env(arg, pos, env);
	}
	else
		printf("CEST PAS BON\n");
}