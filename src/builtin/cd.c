#include "../../includes/minishell.h"

static char	*check_home_path(char *data, char **env)
{
	char	*temp;
	char	*temp2;

	if (!(ft_strncmp(data, "~/", 2)))
	{
		temp = search_in_env_var("HOME", env);
		if (temp)
		{
			temp2 = ft_substr(data, 1, ft_strlen(data));
			temp = ft_strjoin(temp, temp2);
			free(temp2);
			return (temp);
		}
	}
	return (data);
}

static int	change_directory(char *data, char **env)
{
	char	*temp;
	char	*str;

	temp = getcwd(NULL, 0);
	if (temp)
		return (0);
	if (!chdir(data))
	{
		set_var_in_env("OLDPWD", data, env);
		free (temp);
		temp = getcwd(NULL, 0);
		if (temp)
			return (0);
		set_var_in_env("PWD", data, env);
		free (temp);
		return (1);
	}
	return (0);
}

static int	set_directory(char *data, char **env)
{
	if (change_directory(data, env))
		return (1);
}

static int    cd_home(void)
{
	
}

int    ft_cd(char **arg, char **env)
{
    //getenv("HOME") pour recup le path de base
	//changer la var env PWD si jamais on change de repertoire et OLDPWD pour l'ancien repertoire
    if (!arg[2] || ft_strcmp(arg[1], "~") || ft_strcmp(arg[1], "--"))
    {
        if (!getenv("HOME")) //STEP 1
        {
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (1);
        }
        return(cd_home()); //STEP 2
    }
    else if (arg[2])
    {
		check_home_path(arg[1], env);
    }
    else
    {
        printf("usage: cd <directory>\n");
        return (1);
    }
    return (0);
}