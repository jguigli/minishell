#include "../../includes/minishell.h"

void    ft_env(char **env) // var d'env dans struct glob
{
    int i;

    i = 0;
    if (!*env)
        return ;
    while(env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }
}