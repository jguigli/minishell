#include "../../includes/minishell.h"

void	child_process_complex(t_exec_c exec, char **arg, char **envp)
{
	exec.cmd_arg = NULL;
	if (exec.pid_number == 0)
		manage_dup2(exec, 0, exec.pipe[1]);
	else if (exec.pid_number == exec.cmd_number - 1)
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			1);
	else
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			exec.pipe[2 * exec.pid_number + 1]);
	close_pipes(&exec);
	exec.cmd_arg = arg;
	if (!exec.cmd_arg)
		exit(0);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (!exec.cmd)
		exit(0);
	if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		exit(0);
}

void	manage_exec(t_exec_c exec, t_flist *list, char **env)
{
	char		**arg;
	t_flist		*current;

	current = list;
	exec.pid_number = 0;
	create_pipes(&exec);
	while (exec.pid_number < exec.cmd_number)
	{
        shell_parameter_expansion(current->process, env);
		arg = list_to_tab(current->process);
		exec.pid[exec.pid_number] = fork();
		if (exec.pid[exec.pid_number] == -1)
			exit(0);
		else if (!exec.pid[exec.pid_number])
			child_process_complex(exec, arg, env);
		exec.pid_number++;
		free(arg);
        if (current->next) // a supprimer ou pas
		    current = current->next;
        else
            break ;
	}
	close_pipes(&exec);
	exec.pid_number = -1;
	while (++exec.pid_number < exec.cmd_number)
		waitpid(exec.pid[exec.pid_number], NULL, 0);
}

void	exec_complex_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec l'ast => gestion des pipes
{
	t_exec_c	exec;
	int		pipe;

	pipe = my_lstsize(&list) - 1;
    //redir
	exec.pipe_number = 2 * (my_lstsize(&list) - 1);
	exec.cmd_number = my_lstsize(&list);
	exec.pipe = (int *)malloc(sizeof(int) * exec.pipe_number);
	if (!exec.pipe)
		exit(0);
	exec.pid = (pid_t *)malloc(sizeof(pid_t) * exec.cmd_number);
	if (!exec.pid)
	{
		free(exec.pipe);
		exit(0);
	}
	exec.path = search_in_env_var("PATH", env);
	exec.cmd_path = ft_split(exec.path, ':');
	manage_exec(exec, list, env);
}