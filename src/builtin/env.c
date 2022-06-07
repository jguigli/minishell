#include "../../includes/minishell.h"

void    ft_env(char **arg, char **env) // var d'env dans struct glob
{
    int i;

    i = 0;
    if (!arg[1])
    {
        if (!*env)
            return ;
        while(env[i])
        {
            printf("%s\n", env[i]);
            i++;
        }
    }
    else
        printf("env: too much arguments\n");
}