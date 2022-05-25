#include "../../includes/minishell.h"

void    cd_home(void)
{
    
}

void    ft_cd(char *arg)
{
    //getenv("HOME") pour recup le path de base
	//changer la var env PWD si jamais on change de repertoire et OLDPWD pour l'ancien repertoire
    if (argc == 1)
    {
        cd_home();
    }
    else if (argc == 2)
    {
        if (!strcmp(argv[1], "~"))
        {
            cd_home();
            pvvd = getenv("PWD");
            oldpvvd = getenv("OLDPWD");
            printf("PWD = %s\n", pvvd);
            printf("OLDPWD = %s\n", oldpvvd);
        }
        else
        {
            printf("chdir(%s) = %d\n", argv[1], chdir(argv[1]));
            pvvd = getenv("PWD");
            oldpvvd = getenv("OLDPWD");
            printf("PWD = %s\n", pvvd);
            printf("OLDPWD = %s\n", oldpvvd);
        }
    }
    else
    {
        printf("usage: cd <directory>\n");
        return (1);
    }
    return (0);
}