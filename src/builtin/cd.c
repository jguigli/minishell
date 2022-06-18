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

static int	change_directory(char *data, t_main *main)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (!temp)
		return (0);
	if (!chdir(data))
	{
		main->env = set_var_in_env("OLDPWD", temp, main->env);
		free (temp);
		temp = getcwd(NULL, 0);
		if (!temp)
			return (0);
		main->env = set_var_in_env("PWD", temp, main->env);
		free (temp);
		return (1);
	}
	else
	{
		perror("cd");
		status = 1;
	}
	return (0);
}

static int	cd_home(t_main *main)
{
	if (!search_in_env_var("HOME", main->env))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		status = 1;
		return (0);
	}
	return (change_directory(search_in_env_var("HOME", main->env), main));
}

static int	cd_oldpwd(t_main *main)
{
	if (!search_in_env_var("OLDPWD", main->env))
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		status = 1;
		return (0);
	}
	return (change_directory(search_in_env_var("OLDPWD", main->env), main));
}

int	ft_cd(char **arg, t_main *main)
{
	status = 0;
	if (!arg[1] || !ft_strcmp(arg[1], "--"))
		return (cd_home(main));
	else if (!ft_strcmp(arg[1], "-"))
		return (cd_oldpwd(main));
	else if (arg[1] && !arg[2])
	{
		if (change_directory(arg[1], main))
		{
			status = 1;
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		status = 1;
		return (1);
	}
	return (0);
}
