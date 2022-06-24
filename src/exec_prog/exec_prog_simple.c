#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, t_flist *list, t_main *main)
{
	if	(manage_redirections(&list, main) == -5)
		return ;
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(status);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (exec.cmd == NULL || ft_strncmp(exec.cmd, "KO", ft_strlen(exec.cmd)) == 0)
	{
		if (ft_strncmp(exec.cmd, "KO", ft_strlen(exec.cmd)))
		{
			syntax_err_file(FILE, exec.cmd_arg[0]);
		}
		else if	(exec.cmd == NULL)
		{
			freeing_cmd(exec);
		}
		//cmd not found
		// printf("strerror %s\n", strerror(errno));
		// perror("minishell: cmd");
		exit(status);
	}
	if (execve(exec.cmd, exec.cmd_arg, main->env) == -1)
	{
		freeing_execution(exec, errno);
		exit(status);
	}
}

void	manage_child_simple(t_exec_s exec, t_flist *list, t_main *main)
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

int	exec_simple_cmd(t_main *main) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	int		wstatus;
	t_flist	*list;

	init_exec_simple(main, &exec);
	wstatus = 0;
	list = main->start;
	//affiche(main->start->process);
	shell_parameter_expansion(main->start->process, main->env);
	delete_nodes_after_expansion(main->start->process);
	exec.path = search_in_env_var("PATH", main->env);
	exec.cmd_path = ft_split(exec.path, ':');
	//ft_sig_fork(exec.pid);
	if (is_builtin(list->process->first->data))
	{
		if (manage_redirections(&list, main) == -5)
			return (0);
		//printf("rentre ici \n");
		exec.cmd_arg = list_to_tab(list->process);
		if (!exec.cmd_arg)
			exit(status);
		// main->my_fds[0] = open(, O_RDONLY);
		exec_builtin(exec.cmd_arg, main);
		// close(main->my_fds[0]);
	}
	else
	{
		exec.pid = fork();
		//printf("exec.pid == %d\n", exec.pid);
		manage_sig_in_forks(exec.pid, main);
		if (exec.pid == -1)
		{
			printf("Fork failed : %s\n", strerror(errno));
			exit(status);
		}
		else if (exec.pid == 0)
		{
			manage_child_simple(exec, list, main);
			exit(0);
		}
<<<<<<< HEAD
		if (waiting_child_exec(exec.pid, main) == -20)
			return (0);
		manage_signal();
=======
		waitpid(exec.pid, &wstatus, 0);
>>>>>>> origin/manage_free2
	}
	if (main->my_fds[0] != -1000)
	{
		dup2(main->my_oldfds[0], STDOUT_FILENO);
		close(main->my_fds[0]);
	}
	if (main->my_fds[1] != -1000)
	{
		dup2(main->my_oldfds[1], STDIN_FILENO);
		close(main->my_fds[1]);
		//unlink(".hd2");
	}
	free_exec_simple(&exec);
	return (wstatus);
}