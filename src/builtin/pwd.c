#include "../../includes/minishell.h"

int    ft_pwd(char **arg)
{
    char    *str;

    str = getcwd(NULL, 0);
    if (!str)
        return (-1); // MESSAGE ERREUR
    printf("%s\n", str);
    return (0);
}