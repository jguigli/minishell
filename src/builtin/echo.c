#include "../../includes/minishell.h"

static int	n_option(char *arg)
{
	int	i;

	i = 2;
	if (arg[0] != '-' || arg[1] != 'n')
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	manage_print_echo(char **arg, int *i, int *delim, int *n)
{
	if (n_option(arg[*i]) && !*delim)
	{
		(*i)++;
		(*n)++;
	}
	else
	{
		*delim = 1;
		ft_putstr_fd(arg[(*i)++], STDOUT_FILENO);
		if (arg[*i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
}

int	ft_echo(char **arg)
{
	int	i;
	int	n;
	int	delim;

	i = 1;
	n = 0;
	if (!arg[1])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (1);
	}
	while (arg[i])
		manage_print_echo(arg, &i, &delim, &n);
	if (!n)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
