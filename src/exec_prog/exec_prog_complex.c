/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:17:14 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/21 12:44:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	manage_fds(t_main *main)
{
	if (main->my_fds[0] != -1000)
	{
		dup2(main->my_oldfds[0], STDOUT_FILENO);
		close(main->my_fds[0]);
	}
	if (main->my_fds[1] != -1000)
	{
		dup2(main->my_oldfds[1], STDIN_FILENO);
		close(main->my_fds[1]);
	}
}

void	manage_child_complex(t_exec_c exec, t_flist *list, t_main *main)
{
	t_flist		*current;

	current = list;
	child_process_complex(exec, current, main);
}

t_flist	*loop_exec_complex(t_exec_c exec, t_main *main, t_flist *current)
{
	exec.pid[exec.pid_number] = fork();
	manage_sig_in_forks(exec.pid[exec.pid_number], main);
	if (exec.pid[exec.pid_number] == -1)
	{
		write(2, "Fork failed : ", 15);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(0);
	}
	else if (!exec.pid[exec.pid_number])
		manage_child_complex(exec, current, main);
	closing_bis(main);
	current = current->next;
	return (current);
}

void	manage_exec(t_exec_c exec, t_main *main)
{
	t_flist		*current;

	current = main->start;
	exec.pid_number = 0;
	create_pipes(&exec);
	get_origin_fd(main);
	while (current)
	{
		current = loop_exec_complex(exec, main, current);
		usleep(10000);
		exec.pid_number++;
	}
	close_pipes(&exec);
	exec.pid_number = -1;
	while (++exec.pid_number < exec.cmd_number)
	{
		if (waiting_child_exec(exec.pid[exec.pid_number], main,
				exec.pid_number, exec.cmd_number) == -20)
		{
			free_exec_complex_child(&exec);
			return ;
		}
	}
	closing_bis(main);
}

void	exec_complex_cmd(t_main *main)
{
	t_exec_c	exec;
	int			pipe;

	init_exec_complex(main, &exec);
	pipe = my_lstsize(main->start) - 1;
	exec.pipe_number = 2 * pipe;
	exec.cmd_number = my_lstsize(main->start);
	exec.pipe = (int *)malloc(sizeof(int) * exec.pipe_number);
	if (!exec.pipe)
		exit(0);
	exec.pid = (pid_t *)malloc(sizeof(pid_t) * exec.cmd_number);
	if (!exec.pid)
	{
		free(exec.pipe);
		exit(0);
	}
	exec.path = search_in_env_var("PATH", main->env);
	exec.cmd_path = ft_split(exec.path, ':');
	manage_exec(exec, main);
	closing_bis(main);
	free_exec_complex(&exec);
}
