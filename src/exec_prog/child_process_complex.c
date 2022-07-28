/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_complex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:08:55 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:08:57 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	manage_dup(t_exec_c exec)
{
	if (exec.pid_number == 0)
		manage_dup2(exec, 0, exec.pipe[1]);
	else if (exec.pid_number == exec.cmd_number - 1)
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2], 1);
	else
	{
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			exec.pipe[2 * exec.pid_number + 1]);
	}
}

static void	manage_builtin_complex(t_exec_c *exec, t_flist *list, t_main *main)
{
	int	i;

	i = 0;
	(void)list;
	exec_builtin(exec->cmd_arg, main);
	closing(main);
	close(0);
	close(1);
	ft_free(main);
	exit(g_status);
}

static void	error_command_complex(t_exec_c *exec, t_main *main)
{
	int	i;

	i = 0;
	closing_bis(main);
	close(0);
	close(1);
	if (ft_strcmp(exec->cmd, "KO") == 0)
	{
		syntax_err_file(FILE, exec->cmd_arg[0]);
		ft_free(main);
		g_status = 127;
	}
	else
	{
		freeing_cmd_c(exec);
		ft_free(main);
	}
	exit(g_status);
}

static void	error_execve_complex(t_exec_c *exec, t_main *main)
{
	cc_errors(exec->cmd, exec);
	closing_bis(main);
	close(0);
	close(1);
	ft_free(main);
	exit(g_status);
}

void	child_process_complex(t_exec_c exec, t_flist *list, t_main *main)
{
	manage_dup(exec);
	close_pipes(&exec);
	if (shell_parameter_expansion(list->process, main->env))
		exit(g_status);
	delete_nodes_after_expansion(&list->process);
	if (manage_redirections(&list, main) == -5)
		err_cmd_arg(main);
	main->exec_c = &exec;
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		err_cmd_arg(main);
	if (is_builtin(exec.cmd_arg[0]))
		manage_builtin_complex(&exec, list, main);
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd || ft_strcmp(exec.cmd, "KO") == 0)
			error_command_complex(&exec, main);
		if (execve(exec.cmd, exec.cmd_arg, main->env) == -1)
			error_execve_complex(&exec, main);
		close_openfds(main);
	}
}
