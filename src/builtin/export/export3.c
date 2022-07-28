/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:22:01 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:22:03 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_var_env(char *arg, t_main *main)
{
	int	i;

	i = 0;
	if (!search_var_tab(arg, main->env))
	{
		main->env = dup_env_tab_export(main->env);
		while (main->env[i])
			i++;
		main->env[i] = ft_strdup(arg);
		main->env[++i] = 0;
	}
	else
		replace_var_tab_env(arg, main);
}

void	put_in_export_tab(char *arg, t_main *main)
{
	int	i;

	i = 0;
	if (!search_var_tab(arg, main->export))
	{
		main->export = dup_env_tab_export(main->export);
		while (main->export[i])
			i++;
		main->export[i] = ft_strdup(arg);
		main->export[++i] = 0;
	}
	else if (ft_strchr(arg, '='))
		replace_var_tab_export(arg, main);
}

void	replace_var_tab_env(char *arg, t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] != '=' && arg[j])
		j++;
	while (main->env[i])
	{
		if (!ft_strncmp(arg, main->env[i], j))
		{
			free (main->env[i]);
			main->env[i] = ft_strdup(arg);
		}
		i++;
	}
}

void	replace_var_tab_export(char *arg, t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] != '=' && arg[j])
		j++;
	while (main->export[i])
	{
		if (!ft_strncmp(arg, main->export[i], j))
		{
			free (main->export[i]);
			main->export[i] = ft_strdup(arg);
		}
		i++;
	}
}

char	**env_sorted_export(char **env)
{
	int		i;
	int		j;
	char	**tab;
	char	*temp;

	i = 0;
	tab = dup_env_tab(env);
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
