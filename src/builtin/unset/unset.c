/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:22:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:22:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_each_arg_unset(char *arg, int *i)
{
	while (arg[*i])
	{
		if (!ft_isalnum(arg[*i]) && arg[*i] != '_')
			return (0);
		(*i)++;
	}
	return (1);
}

static int	check_arg_unset(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] == '-')
	{
		syntax_err_option(UNSET, arg, OPTION);
		return (0);
	}
	if (arg[0] == '\0')
	{
		syntax_err_builtin(UNSET, arg, IDENTIFIER);
		return (0);
	}
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
	{
		syntax_err_builtin(UNSET, arg, IDENTIFIER);
		return (0);
	}
	if (!check_each_arg_unset(arg, &i))
	{
		syntax_err_builtin(UNSET, arg, IDENTIFIER);
		return (0);
	}
	return (1);
}

void	unset_env(t_main *main, char *arg)
{
	size_t		j;
	size_t		z;

	j = 0;
	while (main->env[j])
	{
		z = 0;
		while (main->env[j][z] != '=' && main->env[j][z])
			z++;
		if (z == ft_strlen(arg))
		{
			if (!ft_strncmp(arg, main->env[j], z))
				main->env = unset_var_env(j, main->env);
		}
		j++;
	}
}

void	unset_export(t_main *main, char *arg)
{
	size_t		j;
	size_t		z;

	j = 0;
	while (main->export[j])
	{
		z = 0;
		while (main->export[j][z] != '=' && main->export[j][z])
			z++;
		if (z == ft_strlen(arg))
		{
			if (!ft_strncmp(arg, main->export[j], z))
				main->export = unset_var_export(j, main->export);
		}
		j++;
	}
}

void	ft_unset(char **arg, t_main *main)
{
	size_t		i;

	i = 1;
	if (!arg || !main->env || !main->export)
		return ;
	while (arg[i])
	{
		if (check_arg_unset(arg[i]))
		{
			unset_env(main, arg[i]);
			unset_export(main, arg[i]);
		}
		i++;
	}
}
