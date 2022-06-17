#include "../../includes/minishell.h"

// static char	*check_home_path(char *data, char **env)
// {
// 	char	*temp;
// 	char	*temp2;
//
// 	if (!(ft_strncmp(data, "~/", 2)))
// 	{
// 		temp = search_in_env_var("HOME", env);
// 		if (temp)
// 		{
// 			temp2 = ft_substr(data, 1, ft_strlen(data));
// 			temp = ft_strjoin(temp, temp2);
// 			free(temp2);
// 			return (temp);
// 		}
// 	}
// 	return (data);
// }

static int	change_directory(char *data, char **env)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (!temp)
		return (0);
	if (!chdir(data))
	{
		env = set_var_in_env("OLDPWD", temp, env);
		free (temp);
		temp = getcwd(NULL, 0);
		if (!temp)
			return (0);
		env = set_var_in_env("PWD", temp, env);
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

static int	cd_home(char **env)
{
	if (!search_in_env_var("HOME", env))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g.status = 1;
		return (0);
	}
	return (change_directory(search_in_env_var("HOME", env), env));
}

static int	cd_oldpwd(char **env)
{
	if (!search_in_env_var("OLDPWD", env))
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		g.status = 1;
		return (0);
	}
	return (change_directory(search_in_env_var("OLDPWD", env), env));
}

int	ft_cd(char **arg, char **env)
{
	g.status = 0;
	if (!arg[1] || !ft_strcmp(arg[1], "--"))
		return (cd_home(env));
	else if (!ft_strcmp(arg[1], "-"))
		return (cd_oldpwd(env));
	else if (arg[1] && !arg[2])
	{
		if (change_directory(arg[1], env))
		{
			g.status = 1;
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g.status = 1;
		return (1);
	}
	return (0);
}
