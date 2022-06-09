#include "../../includes/minishell.h"

void    ft_exit(char **arg)
{
	g.status = 0;
    if (!arg[1] && !arg[2])
    {
        exit(g.status);
    }
    else if (arg[1] && !arg[2])
    {
		if (ft_isdigit(arg[1]))
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