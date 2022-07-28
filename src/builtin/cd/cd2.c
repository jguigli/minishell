/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:33 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:21:34 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	check_pwd_path(t_main *main)
{
	char	*envcheck;
	int		i;

	envcheck = search_in_env_var("PWD", main->env);
	if (!envcheck)
	{
		i = 0;
		main->env = dup_env_tab_export(main->env);
		while (main->env[i])
			i++;
		main->env[i] = ft_strdup("PWD=");
		main->env[++i] = 0;
	}
	else
		free(envcheck);
}

void	check_oldpwd_path(t_main *main)
{
	char	*envcheck;
	int		i;

	i = 0;
	envcheck = search_in_env_var("OLDPWD", main->env);
	if (!envcheck)
	{
		main->env = dup_env_tab_export(main->env);
		while (main->env[i])
			i++;
		main->env[i] = ft_strdup("OLDPWD=");
		main->env[++i] = 0;
	}
	else
		free(envcheck);
}

int	cd_home(t_main *main)
{
	char	*data;

	data = search_in_env_var("HOME", main->env);
	if (!data)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_status = 1;
		return (0);
	}
	return (change_directory(data, main));
}

int	cd_oldpwd(t_main *main)
{
	char	*data;

	data = search_in_env_var("OLDPWD", main->env);
	if (!data)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		g_status = 1;
		return (0);
	}
	return (change_directory(data, main));
}
