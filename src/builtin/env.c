#include "../../includes/minishell.h"

void    ft_env(char **env) // var d'env dans struct glob
{
    int i;

    i = 0;
    if (!*env)
        return ;
    while(env[i])
    {
        write(1, &env[i], ft_strlen(env[i]));
        write(1, "\n", 1);
        i++;
    }
}