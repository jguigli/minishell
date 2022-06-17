#include "../../includes/minishell.h"

static int	check_digit_exit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_one_arg(char *arg)
{
	if (check_digit_exit(arg))
		g.status = ft_atoi(arg);
	else
	{
		printf("minishell: exit: numeric argument required\n");
		g.status = 2;
	}
	exit(g.status);
}

static void	exit_multi_arg(char *arg)
{
	if (!check_digit_exit(arg))
	{
		printf("minishell: exit: numeric argument required\n");
		g.status = 2;
		exit(g.status);
	}
	printf("minishell: exit: too much arguments\n");
	g.status = 1;
}

void	ft_exit(char **arg)
{
	int	i;

	i = 0;
	g.status = 0;
	if (!arg[1] && !arg[2])
		exit(g.status);
	else if (arg[1] && !arg[2])
		exit_one_arg(arg[1]);
	else
		exit_multi_arg(arg[1]);
}
