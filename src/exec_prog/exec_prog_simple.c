/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:08:28 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:08:30 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	manage_child_simple(t_exec_s exec, t_flist *list, t_main *main)
{
	if (main->my_fds[0] != -1000)
	{
		close(main->my_fds[0]);
	}
	if (main->my_fds[1] != -1000)
	{
		close(main->my_fds[1]);
	}
	child_process_simple(exec, list, main);
}

static int	manage_builtin(t_exec_s *exec, t_main *main)
{
	if (manage_redirections(&main->start, main) == -5)
	{
		closing_bis(main);
		free_exec_simple(exec);
		return (1);
	}
	exec->cmd_arg = list_to_tab(main->start->process);
	if (!exec->cmd_arg)
	{
		closing(main);
		free_exec_simple(exec);
		return (EXIT_FAILURE);
	}
	exec_builtin(exec->cmd_arg, main);
	return (0);
}

static int	manage_fork(t_exec_s exec, t_main *main)
{
	exec.pid = fork();
	manage_sig_in_forks(exec.pid, main);
	if (exec.pid == -1)
	{
		printf("Fork failed : %s\n", strerror(errno));
		free_exec_simple(&exec);
		return (1);
	}
	else if (exec.pid == 0)
		manage_child_simple(exec, main->start, main);
	if (waiting_child_exec(exec.pid, main, 0, 1) == -20)
	{
		free_exec_simple(&exec);
		return (1);
	}
	return (0);
}

int	exec_simple_cmd(t_main *main)
{
	t_exec_s	exec;

	init_exec_simple(main, &exec);
	get_origin_fd(main);
	if (shell_parameter_expansion(main->start->process, main->env))
		return (-10);
	delete_nodes_after_expansion(&main->start->process);
	exec.path = search_in_env_var("PATH", main->env);
	exec.cmd_path = ft_split(exec.path, ':');
	if (is_builtin(main->start->process->first->data))
	{
		if (manage_builtin(&exec, main))
			return (closing(main), -10);
	}
	else
	{
		if (manage_fork(exec, main))
			return (closing(main), -10);
	}
	manage_signal();
	closing(main);
	free_exec_simple(&exec);
	return (g_status);
}
