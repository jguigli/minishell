/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:24 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:21:26 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	free_in_cd(char *temp, char *data)
{
	if (temp)
		free (temp);
	free (data);
}

static int	check_option_cd(char *arg)
{
	if (arg[0] == '-')
	{
		if (arg[1] == '-' && !arg[2])
			return (1);
		else
		{
			syntax_err_option(CD, arg, OPTION);
			return (0);
		}
	}
	return (1);
}

int	change_directory(char *data, t_main *main)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (data[0] == '\0')
	{
		free_in_cd(temp, data);
		return (0);
	}
	if (!chdir(data))
	{
		check_pwd_path(main);
		check_oldpwd_path(main);
		main->env = set_var_in_env("OLDPWD", temp, main->env);
		if (temp)
			free (temp);
		temp = getcwd(NULL, 0);
		main->env = set_var_in_env("PWD", temp, main->env);
		if (temp)
			free (temp);
		free (data);
		return (1);
	}
	err_chdir(CD, data);
	free_in_cd(temp, data);
	return (0);
}

int	ft_cd(char **arg, t_main *main)
{
	g_status = 0;
	if (!arg[1] || !ft_strcmp(arg[1], "--") || !ft_strcmp(arg[1], "~"))
		return (cd_home(main));
	else if (!ft_strcmp(arg[1], "-"))
		return (cd_oldpwd(main));
	else if (arg[1] && !arg[2])
	{
		if (check_option_cd(arg[1]))
		{
			if (change_directory(ft_strdup(arg[1]), main))
			{
				g_status = 1;
				return (1);
			}
		}
	}
	else
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_status = 1;
		return (1);
	}
	return (0);
}
