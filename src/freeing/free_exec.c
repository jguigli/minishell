/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:07:00 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:07:02 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_exec_simple(t_exec_s *exec)
{
	int		i;

	if (exec->cmd_path)
	{
		i = 0;
		while (exec->cmd_path[i])
			free(exec->cmd_path[i++]);
		free(exec->cmd_path);
	}
	if (exec->path)
		free(exec->path);
	if (exec->cmd_arg)
	{
		i = 0;
		while (exec->cmd_arg[i])
			free(exec->cmd_arg[i++]);
		free(exec->cmd_arg);
	}
	if (exec->cmd)
		free(exec->cmd);
}

void	free_exec_complex(t_exec_c *exec)
{
	int		i;

	if (exec->pid)
		free(exec->pid);
	if (exec->pipe)
		free(exec->pipe);
	if (exec->path)
		free(exec->path);
	if (exec->cmd_path)
	{
		i = 0;
		while (exec->cmd_path[i])
			free(exec->cmd_path[i++]);
		free(exec->cmd_path);
	}
	if (exec->cmd_arg)
	{
		i = 0;
		while (exec->cmd_arg[i])
			free(exec->cmd_arg[i++]);
		free(exec->cmd_arg);
	}
	if (exec->cmd)
		free(exec->cmd);
}

void	free_exec_complex_child(t_exec_c *exec)
{
	int		i;

	if (exec->cmd_arg)
	{
		i = 0;
		while (exec->cmd_arg[i])
			free(exec->cmd_arg[i++]);
		free(exec->cmd_arg);
	}
	if (exec->cmd)
		free(exec->cmd);
}
