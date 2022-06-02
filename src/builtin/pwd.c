#include "../../includes/minishell.h"

int    ft_pwd(void)
{
	// size_t  size;
    char    *str;

	// size = 255;
    str = getcwd(NULL, 0);
    // if (getcwd(str, size))
    // {
    //     free(str);
    //     size *= 2;
    //     str = malloc(sizeof(char) * size);
    //     getcwd(str, size);
    // }
    if (!str)
        return (-1);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    return (0);
}