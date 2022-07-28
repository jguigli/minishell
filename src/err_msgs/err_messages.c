/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_messages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:19:47 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:19:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_msgs(int error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(error), 2);
	ft_putstr_fd("\n", 2);
	g_status = 1;
}

void	error_msg_redir(char *data, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 1;
}

void	syntax_err(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd("\n", 2);
	g_status = 2;
}

void	syntax_err_identifier(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 1;
}

void	syntax_err_file(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = 2;
}
