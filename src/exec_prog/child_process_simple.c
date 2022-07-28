/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:19:00 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:19:02 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	error_command(t_exec_s *exec, t_flist *list, t_main *main)
{
	(void)list;
	closing(main);
	if (!ft_strcmp(exec->cmd, "KO"))
	{
		syntax_err_file(FILE, exec->cmd_arg[0]);
		ft_free(main);
		g_status = 127;
	}
	else if (exec->cmd == NULL
		|| ft_strncmp(exec->cmd, "(null)", ft_strlen("(null)")) == 0)
	{
		freeing_cmd(exec);
		ft_free(main);
		g_status = 127;
	}
	close(0);
	close(1);
	exit(g_status);
}

static void	error_execve(t_exec_s *exec, t_flist *list, t_main *main)
{
	(void)list;
	if (ft_strcmp(exec->cmd, "..") == 0)
		freeing_cmd(exec);
	else if (ft_strlen(exec->cmd) == 17
		&& ft_strcmp(exec->cmd, "/usr/local/sbin/.") == 0)
	{
		syntax_err("filename argument required", exec->cmd);
		printf("%s: usage: %s filename [arguments]\n", exec->cmd, exec->cmd);
		g_status = 2;
	}
	else if (ft_strchrr(exec->cmd, '/') == 2 && !check_stat(exec->cmd))
	{
		isdir_err(DIR_ERR, exec->cmd);
		g_status = 126;
	}
	else
	{
		error_msgs(errno, exec->cmd);
		g_status = 126;
	}
	closing(main);
	ft_free(main);
	close(0);
	close(1);
	exit(g_status);
}

void	child_process_simple(t_exec_s exec, t_flist *list, t_main *main)
{
	main->exec_s = &exec;
	if (manage_redirections(&list, main) == -5)
	{
		closing(main);
		ft_free(main);
		close(0);
		close(1);
		exit (EXIT_FAILURE);
	}
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
	{
		closing(main);
		ft_free(main);
		exit(g_status);
	}
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (exec.cmd == NULL || !ft_strcmp(exec.cmd, "KO"))
		error_command(&exec, list, main);
	else if (execve(exec.cmd, exec.cmd_arg, main->env) == -1)
		error_execve(&exec, list, main);
}
