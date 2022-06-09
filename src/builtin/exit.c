#include "../../includes/minishell.h"

static int		check_digit_exit(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void    ft_exit(char **arg)
{
	g.status = 0;
    if (!arg[1] && !arg[2])
    {
        exit(g.status);
    }
    else if (arg[1] && !arg[2])
    {
		if (check_digit_exit(arg[1]))
        	g.status = ft_atoi(arg[1]);
        else
		{
            printf("minishell: exit: numeric argument required\n");
			g.status = 2;
		}
        exit(g.status);
    }
    else
	{
        printf("minishell: exit: too much arguments\n");
		g.status = 1;
	}
}