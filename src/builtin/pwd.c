#include "../../includes/minishell.h"

int    ft_pwd(void)
{
    char    *str;

    str = getcwd(NULL, 0);
    if (!str)
        return (-1); // MESSAGE ERREUR
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    return (0);
}