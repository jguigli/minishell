/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:23:33 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:23:35 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static unsigned long long	ft_atoi_exit(const char *str, int *nope)
{
	int					negative;
	unsigned long long	rep;
	unsigned long long	i;

	negative = 1;
	rep = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rep *= 10;
		rep += str[i] - 48;
		i++;
	}
	if ((rep > LLONG_MAX && negative == 1)
		|| (rep - 1 > LLONG_MAX && negative == -1))
		*nope = 1;
	return (rep * negative);
}

static int	check_digit_exit(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '+' && arg[0] != '-' && !ft_isdigit(arg[0]))
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_one_arg(char *arg, t_main *main)
{
	int		nope;

	nope = 0;
	write(1, "exit\n", 6);
	if (check_digit_exit(arg))
	{
		g_status = ft_atoi_exit(arg, &nope);
		if (nope)
		{
			g_status = 2;
			syntax_err_builtin(EXIT, arg, NUMARG);
		}
	}
	else
	{
		g_status = 2;
		syntax_err_builtin(EXIT, arg, NUMARG);
	}
	closing(main);
	ft_free(main);
	exit(g_status);
}

static void	exit_multi_arg(char *arg, t_main *main)
{
	write(1, "exit\n", 6);
	if (!check_digit_exit(arg))
	{
		syntax_err_builtin(EXIT, arg, NUMARG);
		g_status = 2;
		closing(main);
		ft_free(main);
		exit(g_status);
	}
	printf("minishell: exit: too much arguments\n");
	g_status = 1;
}

void	ft_exit(char **arg, t_main *main)
{
	g_status = 0;
	if (!arg[1])
	{
		closing(main);
		ft_free(main);
		close(0);
		close(1);
		exit(g_status);
	}
	else if (arg[1] && !arg[2])
		exit_one_arg(arg[1], main);
	else
		exit_multi_arg(arg[1], main);
}
