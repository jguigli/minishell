#include "../../includes/minishell.h"

void    ft_exit(char **arg)
{
    int status;

    if (!arg[1] && !arg[2])
    {
        exit(0);
    }
    else if (!arg[2])
    {
        status = ft_atoi(arg[1]);
        exit(status);
    }
    else
        printf("minishell: exit: too much arguments\n");
}