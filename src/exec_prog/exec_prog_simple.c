#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, t_flist *list, char **envp)
{
	if	(manage_redirections(&list) == -5)
	{
		printf("loul\n");
		return ;
	}
	//printf("loullllll\n");
	affiche(list->process);
	exec.cmd_arg = list_to_tab(list->process);
	printf("exec cmd = %s\n", exec.cmd_arg[0]);
	if (!exec.cmd_arg)
	{

		//printf("datta %s\n", exec.cmd_arg[0]);
		exit(0);
	}
	if (is_builtin(exec.cmd_arg[0]))
	{
		exec_builtin(exec.cmd_arg, envp);
		exit(g.status);
	}
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd || ft_strcmp(exec.cmd, "KO") == 0)
		{
			if (ft_strcmp(exec.cmd, "KO") == 0)
			{
				syntax_err_file(FILE, exec.cmd_arg[0]);
			}
			else
			{
				freeing_cmd(exec);

			}
				//cmd not found
			// printf("strerror %s\n", strerror(errno));
			// perror("minishell: cmd");
			exit(g.status);
		}
		if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		{
			printf("hihoo ici1\n");
			freeing_execution(exec, errno);
			exit(g.status);
		}
	}
}

int	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;
	int		file;
	int		wstatus;

	wstatus = 0;
	shell_parameter_expansion(list->process, env);
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	exec.pid = fork();
	ft_sig_fork(exec.pid);
	if (exec.pid == -1)
	{
		printf("Fork failed : %s\n", strerror(errno));
		exit(g.status);
	}
	else if (!exec.pid)
	{
		if (g.my_fds[0] != -1000)
			close(g.my_fds[0]);
		if (g.my_fds[1] != -1000)
			close(g.my_fds[1]);
		//affiche(list->process);
		child_process_simple(exec, list, env);
	}
	close(g.my_fds[0]);
	close(g.my_fds[1]);
	//free(arg);
	waitpid(exec.pid, &wstatus, 0);
	return (wstatus);
}