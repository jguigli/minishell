/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:47 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:21:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_each_arg(char *arg, int *i)
{
	while (arg[*i] != '=' && arg[*i])
	{
		if (!ft_isalnum(arg[*i]) && arg[0] != '_')
			return (0);
		(*i)++;
	}
	(*i)++;
	while (arg[*i])
	{
		if (!ft_isalnum(arg[*i]) && !export_appreciate_symbol(arg[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

static int	check_plus_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '+' && arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[0] != '_')
			return (0);
		i++;
	}
	if ((arg[i] == '+' && arg[i + 1] == '=') || arg[i] == '=')
		i++;
	else
		return (0);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && !export_appreciate_symbol(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_arg_export2(char *arg)
{
	int	i;

	i = 1;
	if (!ft_strchr(arg, '='))
		return (2);
	if (ft_strchr(arg, '+'))
	{
		if (check_plus_arg(arg))
			return (3);
		else
		{
			syntax_err_builtin(EXPORT, arg, IDENTIFIER);
			return (0);
		}
	}
	if (!check_each_arg(arg, &i))
	{
		syntax_err_builtin(EXPORT, arg, IDENTIFIER);
		return (0);
	}
	return (1);
}

static int	check_arg_export(char *arg)
{
	if (arg[0] == '\0')
	{
		syntax_err_builtin(EXPORT, arg, IDENTIFIER);
		return (0);
	}
	if (arg[0] == '-')
	{
		syntax_err_option(EXPORT, arg, OPTION);
		return (0);
	}
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
	{
		syntax_err_builtin(EXPORT, arg, IDENTIFIER);
		return (0);
	}
	if (ft_strchr(arg, ' ') && !ft_strchr(arg, '='))
	{
		syntax_err_builtin(EXPORT, arg, IDENTIFIER);
		return (0);
	}
	return (check_arg_export2(arg));
}

void	ft_export(char **arg, t_main *main)
{
	int	i;
	int	verif;

	i = 0;
	g_status = 0;
	if (!arg[1])
		return (print_export(main));
	while (arg[++i])
	{
		verif = check_arg_export(arg[i]);
		if (verif == 1)
		{
			export_var_env(arg[i], main);
			put_in_export_tab(arg[i], main);
		}
		else if (verif == 2)
			put_in_export_tab(arg[i], main);
		else if (verif == 3)
		{
			export_var_env_plus(arg[i], main);
			put_in_export_tab_plus(arg[i], main);
		}
	}
}
