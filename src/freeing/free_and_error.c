/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:06:51 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:06:53 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	freeing_execution(t_exec_s exec, int error)
{
	(void)exec;
	error_msgs(error, "");
}

void	freeing_cmd(t_exec_s *exec)
{
	(void)exec;
	cmd_not_found(CMD, exec->cmd_arg[0]);
}

void	freeing_execution_c(t_exec_c exec, int error)
{
	(void)exec;
	error_msgs(error, "");
}

void	freeing_cmd_c(t_exec_c *exec)
{
	cmd_not_found(CMD, exec->cmd_arg[0]);
}
