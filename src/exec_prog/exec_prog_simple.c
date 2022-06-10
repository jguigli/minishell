#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, t_flist *list, char **envp)
{
	manage_redirections(&list);
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(0);
	if (is_builtin(exec.cmd_arg[0]))
	{
		exec_builtin(exec.cmd_arg, envp);
	}
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd)
		{
			perror("minishell: cmd");
			g.status = 127;
			return ;
		}
		//printf("exec cmd = %s\n", exec.cmd);
		if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		{
			perror("minishell: cmd");
			g.status = 126;
			return ;
		}
	}
}

int	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;
	int		file;
	int		wstatus;

//	affiche(list->process);
	wstatus = 0;
	shell_parameter_expansion(list->process, env);
	//file = manage_redirections(&list);
	//affiche(list->process);
	//printf("file == %d \n", file);
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	// arg = list_to_tab(list->process);
	exec.pid = fork();
	if (exec.pid == -1)
		exit(0);
	else if (!exec.pid)
		child_process_simple(exec, list, env);
	//close(file);
	//free(arg);
	waitpid(exec.pid, &wstatus, 0);
	// printf("wstatus --> %d \n", wstatus);
	// printf("G.STATUS dans exec_simple_cmd = %d\n", g.status);
	return (wstatus);
}