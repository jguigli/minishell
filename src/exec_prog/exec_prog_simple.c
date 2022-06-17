#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, t_flist *list, char **envp)
{
	if (manage_redirections(&list) == -5)
		return ;
	//exec.cmd_arg = list_to_tab(list->process);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (!exec.cmd)
	{
		// printf("strerror %s\n", strerror(errno));
		// perror("minishell: cmd");
		freeing_cmd(exec);
		exit(g.status);
	}
	//printf("exec cmd = %s\n", exec.cmd);
	if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
	{
		freeing_execution(exec, errno);
		exit(g.status);
	}
}

void	manage_child_simple(t_exec_s exec, t_flist *list, char **env)
{
	t_flist		*current;

	current = list;
	if (g.my_fds[0] != -1000)
		close(g.my_fds[0]);
	if (g.my_fds[1] != -1000)
		close(g.my_fds[1]);
	child_process_simple(exec, list, env);
}

int	exec_simple_cmd(t_flist *list, char **env)
{
	t_exec_s	exec;
	int			file;
	int			wstatus;

	//affiche(list->process);
	wstatus = 0;
	exec.cmd_path = NULL;
	shell_parameter_expansion(list->process, env);
	//file = manage_redirections(&list);
	//affiche(list->process);
	//printf("file == %d \n", file);
	exec.path = search_in_env_var("PATH", env);
	exec.cmd_path = ft_split(exec.path, ':');
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(g.status);
	if (is_builtin(exec.cmd_arg[0]))
		exec_builtin(exec.cmd_arg, env);
	else
	{
		exec.pid = fork();
		if (exec.pid == -1)
		{
			printf("Fork failed : %s\n", strerror(errno));
			exit(g.status);
		}
		else if (!exec.pid)
			manage_child_simple(exec, list, env);
	}
	//close(file);
	//free(arg);
	waitpid(exec.pid, &wstatus, 0);
	return (wstatus);
}
