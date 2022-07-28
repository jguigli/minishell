/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_messages2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:19:56 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:19:58 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	syntax_err_option(char *function, char *data, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd(": ", 2);
	ft_putchar_fd(data[0], 2);
	ft_putchar_fd(data[1], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 2;
}

void	syntax_err_builtin(char *function, char *data, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd(": '", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 1;
}

void	err_chdir(char *function, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd(": ", 2);
	perror(data);
	g_status = 1;
}

void	isdir_err(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 126;
}

void	cmd_not_found(char *error, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 127;
}
