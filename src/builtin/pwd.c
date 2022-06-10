#include "../../includes/minishell.h"

int    ft_pwd(char **arg)
{
    char    *str;

    g.status = 0;
    str = getcwd(NULL, 0);
    if (!str)
        return (-1); // MESSAGE ERREUR
    //printf("%s\n", str);
    return (0);
}