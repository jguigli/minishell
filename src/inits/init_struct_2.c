/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:04:57 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:04:58 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_exec_simple(t_main *main, t_exec_s *exec)
{
	main->exec_s = exec;
	exec->path = NULL;
	exec->cmd_path = NULL;
	exec->cmd_arg = NULL;
	exec->cmd = NULL;
}

void	init_exec_complex(t_main *main, t_exec_c *exec)
{
	main->exec_c = exec;
	exec->pipe = NULL;
	exec->path = NULL;
	exec->cmd_path = NULL;
	exec->cmd_arg = NULL;
	exec->cmd = NULL;
}
