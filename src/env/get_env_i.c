#include "../../includes/minishell.h"

char    **manage_env_i(void)
{
    char    **tab;
    char    *temp;

    tab = malloc(sizeof(char*) * 3);
    if (!tab)
        return (NULL);
    temp = ft_strdup("PWD=");
    temp = ft_strjoin(temp, getcwd(NULL, 0));
    tab[0] = ft_strdup("PATH=/bin");
    tab[1] = ft_strdup(temp);
    tab[2] = 0;
    free (temp);
    return (tab);
}