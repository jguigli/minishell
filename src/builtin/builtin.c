#include "../../includes/minishell.h"

/*
BUILTIN :
echo -n
cd (only chemin relatif ou absolu)
pwd
export
unset
env
exit
*/

void    ft_env(char **env) // var d'env dans struct glob
{
    int i;

    i = 0;
    while(env[i])
    {
        write(1, &env[i], ft_strlen(env[i]));
        write(1, "\n", 1);
        i++;
    }
}

void    ft_echo(char **arg)
{
	if (!arg[1])
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	//checker si -n est present
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		i++;
		if (arg[i])
			ft_putchar_fd(' ', 1);
	}
	if (n)
		ft_putchar_fd('\n');
	return (0);
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

void    ft_pwd(char **env)
{
	size_t  size;
    char    *str;

	size = 255;
    str = malloc(sizeof(char) * size);
    if (!getcwd(str, size))
    {
        free(str);
        size *= 2;
        str = malloc(sizeof(char) * size);
        getcwd(str, size);
    }
    if (!str)
        return (-1);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    return (0);
}

void    ft_export(char **str)
{
    
}

void    ft_unset(char **str)
{
    
}

void    ft_exit(char **str)
{
    
    exit(0);
}