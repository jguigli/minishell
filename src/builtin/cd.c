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
	if (!temp)
		return (0);
	if (!chdir(data))
	{
		g.env = set_var_in_env("OLDPWD", temp, env);
		free (temp);
		temp = getcwd(NULL, 0);
		if (!temp)
			return (0);
		g.env = set_var_in_env("PWD", temp, env);
		free (temp);
		return (1);
	}
	else
	{
		perror("cd");
		g.status = 1;
	}
	return (0);
}

static int	set_directory(char *data, char **env)
{
	if (change_directory(data, env))
		return (1);
	return (0);
}

static int    cd_home(char **env)
{
	if (set_directory(search_in_env_var("HOME", env), env))
		return (1);
	return (0);
}

int    ft_cd(char **arg, char **env)
{
	g.status = 0;
    if (!arg[1] || !ft_strcmp(arg[1], "~") || !ft_strcmp(arg[1], "--"))
    {
        if (!search_in_env_var("HOME", env)) //STEP 1
        {
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			g.status = 1;
			return (1);
        }
        return(cd_home(env)); //STEP 2
    }
    else if (arg[1] && !arg[2])
    {
		if (set_directory(check_home_path(arg[1], env), env))
		{
			g.status = 1;
			return (1);
		}
    }
    else
    {
        printf("usage: cd <directory>\n");
		g.status = 1;
        return (1);
    }
    return (0);
}