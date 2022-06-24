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

static void	exit_one_arg(char *arg, t_main *main)
{
	if (check_digit_exit(arg))
		status = ft_atoi(arg);
	else
	{
		printf("minishell: exit: numeric argument required\n");
		status = 2;
	}
	ft_free(main);
	free_exec_simple(main->exec_s);
	exit(status);
}

static void	exit_multi_arg(char *arg, t_main *main)
{
	if (!check_digit_exit(arg))
	{
		printf("minishell: exit: numeric argument required\n");
		status = 2;
		ft_free(main);
		free_exec_simple(main->exec_s);
		exit(status);
	}
	printf("minishell: exit: too much arguments\n");
	status = 1;
}

void	ft_exit(char **arg, t_main *main)
{
	status = 0;
	if (!arg[1])
	{
		ft_free(main);
		//free_exec_simple(main->exec_s);
		exit(status);
	}
	else if (arg[1] && !arg[2])
		exit_one_arg(arg[1], main);
	else
		exit_multi_arg(arg[1], main);
}
