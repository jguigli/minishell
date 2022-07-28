/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:22:11 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:22:12 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_var_env_plus(char *arg, t_main *main)
{
	int	i;

	i = 0;
	if (!search_var_tab_plus(arg, main->env))
	{
		main->env = dup_env_tab_export(main->env);
		while (main->env[i])
			i++;
		main->env[i] = ft_dup_without_plus(arg);
		main->env[++i] = 0;
	}
	else
		replace_var_tab_env_plus(arg, main);
}

void	put_in_export_tab_plus(char *arg, t_main *main)
{
	int	i;

	i = 0;
	if (!search_var_tab_plus(arg, main->export))
	{
		main->export = dup_env_tab_export(main->export);
		while (main->export[i])
			i++;
		main->export[i] = ft_dup_without_plus(arg);
		main->export[++i] = 0;
	}
	else
		replace_var_tab_export_plus(arg, main);
}

void	replace_var_tab_env_plus(char *arg, t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] != '+' && arg[j])
		j++;
	while (main->env[i])
	{
		if (!ft_strncmp(arg, main->env[i], j))
		{
			main->env[i] = ft_dup_plus(arg, main->env[i]);
			return ;
		}
		i++;
	}
}

void	replace_var_tab_export_plus(char *arg, t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] != '+' && arg[j])
		j++;
	while (main->export[i])
	{
		if (!ft_strncmp(arg, main->export[i], j))
		{
			main->export[i] = ft_dup_plus(arg, main->export[i]);
			return ;
		}
		i++;
	}
}
