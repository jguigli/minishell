#include "../../includes/minishell.h"

void	manage_dup(t_exec_c exec)
{
	if (exec.pid_number == 0)
	{
		//printf("here5\n");
		manage_dup2(exec, 0, exec.pipe[1]);
	}
	else if (exec.pid_number == exec.cmd_number - 1)
	{
		//printf("here6\n");
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2], 1);
	}
	else
	{
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			exec.pipe[2 * exec.pid_number + 1]);
	}	
}

void	child_process_complex(t_exec_c exec, t_flist *list, t_main *main)
{
	manage_dup(exec);
	close_pipes(&exec);
	manage_redirections(&list, main);
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(0);
	if (is_builtin(exec.cmd_arg[0]))
	{
		exec_builtin(exec.cmd_arg, main);
		exit(status);
	}
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd || ft_strcmp(exec.cmd, "KO") == 0)
		{
			if (ft_strcmp(exec.cmd, "KO") == 0)
				syntax_err_file(FILE, exec.cmd_arg[0]);
			else
				freeing_cmd_c(exec);
			exit(status);
		}
		if (execve(exec.cmd, exec.cmd_arg, main->env) == -1)
		{
			freeing_execution_c(exec, errno);
			exit(status);
		}
	}
}

void	manage_child_complex(t_exec_c exec, t_flist *list, t_main *main)
{
	t_flist		*current;

	current = list;
	child_process_complex(exec, current, main);
}

void	manage_exec(t_exec_c exec, t_main *main)
{
	t_flist		*current;

	current = main->start;
	exec.pid_number = 0;
	create_pipes(&exec);
	while (current)
	{
		//affiche(current->process);
        shell_parameter_expansion(current->process, main->env);
		delete_nodes_after_expansion(current->process);
		exec.pid[exec.pid_number] = fork();
		//ft_sig_fork(exec.pid[exec.pid_number]);
		if (exec.pid[exec.pid_number] == -1)
		{
			printf("Fork failed : %s\n", strerror(errno));
			exit(0);
		}
		else if (!exec.pid[exec.pid_number])
			manage_child_complex(exec, current, main);
		exec.pid_number++;
		current = current->next;
	}
	close_pipes(&exec);
	exec.pid_number = -1;
	while (++exec.pid_number < exec.cmd_number)
		waiting_child_exec(exec.pid[exec.pid_number], main);
	manage_signal();
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

void	exec_complex_cmd(t_main *main) // exécution de la ligne de commande avec l'ast => gestion des pipes
{
	t_exec_c	exec;
	int		pipe;

	pipe = my_lstsize(main->start) - 1;
	exec.pipe_number = 2 * pipe;
	exec.cmd_number = my_lstsize(main->start);
	exec.pipe = (int *)malloc(sizeof(int) * exec.pipe_number);
	if (!exec.pipe)
		exit(0);
	exec.pid = (pid_t *)malloc(sizeof(pid_t) * exec.cmd_number);
	manage_sig_in_forks(exec.pid, main);
	if (!exec.pid)
	{
		free(exec.pipe);
		exit(0);
	}
	exec.path = search_in_env_var("PATH", main->env);
	exec.cmd_path = ft_split(exec.path, ':');
	manage_exec(exec, main);
}