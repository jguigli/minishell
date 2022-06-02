#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, char **arg, char **envp)
{
	exec.cmd_arg = arg;
	if (!exec.cmd_arg)
		exit(0);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (!exec.cmd)
		exit(0);
	if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		exit(0);
}

void	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;

	shell_parameter_expansion(list->process, env);
	//redir
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	arg = list_to_tab(list->process);
	if (is_builtin(arg[0]))
		exec_builtin(arg, env);
	else
	{
		exec.pid = fork();;
		if (exec.pid == -1)
			exit(0);
		else if (!exec.pid)
			child_process_simple(exec, arg, env);
	}
	free(arg);
	waitpid(exec.pid, NULL, 0);
}