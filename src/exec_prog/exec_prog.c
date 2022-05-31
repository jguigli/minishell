#include "../../includes/minishell.h"

static int	count_quote(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		if (argv[i] == 39)
			count++;
	}
	return (count);
}

char	**split_arg(char *argv)
{
	int		count;
	char	**tab;

	count = count_quote(argv);
	if (count == 2)
		tab = ft_split_cmd_quote(argv);
	else
		tab = ft_split(argv, ' ');
	return (tab);
}

int	check_arg(char *argv)
{
	int	i;
	int	count;
	int	final;

	i = 0;
	count = 0;
	final = ft_strlen(argv);
	if (argv[0] == ' ' || argv[final - 1] == ' ')
		return (1);
	while (argv[i])
	{
		if (ft_isalpha(argv[i]))
		{
			count++;
			while (ft_isalpha(argv[i + 1]))
				i++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

char	*get_command(char **path, char *cmd)
{
	char	*temp;
	char	*path_cmd;

	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK) == 0 && cmd[0] == '/')
		return (cmd);
	while (*path)
	{
		if (cmd[0] == '/')
			return (NULL);
		temp = ft_strjoin(*path, "/");
		path_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_cmd, 0) == 0)
			return (path_cmd);
		free(path_cmd);
		path++;
	}
	return (NULL);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

void	create_pipes(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec->cmd_number - 1)
	{
		if (pipe(exec->pipe + 2 * i) < 0)
			write_error_path(ERROR_PIPE, exec);
		i++;
	}
}

void	close_pipes(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec->pipe_number)
	{
		close(exec->pipe[i]);
		i++;
	}
}

void	manage_dup2(t_exec exec, int first, int second)
{
	if (dup2(first, STDIN_FILENO) < 0)
	{
		free_path(&exec);
		write_error_path(ERROR_DUP, &exec);
	}
	if (dup2(second, STDOUT_FILENO) < 0)
	{
		free_path(&exec);
		write_error_path(ERROR_DUP, &exec);
	}
}

void	child_process(t_exec exec, char **argv, char **envp)
{
	exec.cmd_arg = NULL;
	if (exec.pid_number == 0)
		manage_dup2(exec, exec.file1, exec.pipe[1]);
	else if (exec.pid_number == exec.cmd_number - 1)
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			exec.file2);
	else
		manage_dup2(exec, exec.pipe[2 * exec.pid_number - 2],
			exec.pipe[2 * exec.pid_number + 1]);
	close_pipes(&exec);
	exec.cmd_arg = split_arg(argv[2 + exec.pid_number]);
	if (check_arg(argv[2 + exec.pid_number]))
		exec.cmd_arg = ft_split(argv[2 + exec.pid_number], 0);
	else
		exec.cmd_arg = split_arg(argv[2 + exec.pid_number]);
	if (!exec.cmd_arg)
		write_error_path(ERROR_CMD_ARG, &exec);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (!exec.cmd)
		write_free_all(ERROR_CMD, &exec);
	if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		write_free_all(ERROR_EXECV, &exec);
}

void	manage_exec(t_exec exec, char **env)
{
	exec.pid_number = 0;
	create_pipes(&exec);
	while (exec.pid_number < exec.pipe_number + 1)
	{
		exec.pid[exec.pid_number] = fork();
		if (exec.pid[exec.pid_number] == -1)
			write_error_path(ERROR_PID, &exec);
		else if (!exec.pid[exec.pid_number])
			child_process(exec, argv, envp);
		exec.pid_number++;
	}
	close_pipes(&exec);
	exec.pid_number = -1;
	while (++exec.pid_number < exec.cmd_number)
		waitpid(exec.pid[exec.pid_number], NULL, 0);
}

void	exec_complex_cmd(t_flist *list) // exécution de la ligne de commande avec l'ast => gestion des pipes
{
	t_exec	exec;
	int		pipe;

	pipe = my_lstsize(list) - 1;
	while (list)
	{

		shell_parameter_expansion(list->process, env);
		//redir
		//list_to_tab
	}
	//exec.cmd_number = argc - 3;
	exec.pipe_number = 2 * pipe;
	exec.pipe = (int *)malloc(sizeof(int) * exec.pipe_number);
	if (!exec.pipe)
		write_error_path(ERROR_PIPEALLOC, &exec);
	exec.pid = (pid_t *)malloc(sizeof(pid_t) * exec.cmd_number);
	if (!exec.pid)
	{
		free(exec.pipe);
		write_error_path(ERROR_PIDALLOC, &exec);
	}
	exec.path = find_path(envp);
	exec.cmd_path = ft_split(exec.path, ':');
	manage_exec(exec, env);
}

void	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	shell_parameter_expansion(list, env);
}

int	exec_launcher(t_flist *list, char **env)
{
	int	pipe;

	shell_parameter_expansion(fin_li, env);
	pipe = my_lstsize(list) - 1;
	if (pipe)
		exec_complex_cmd(list);
	else
		exec_simple_cmd(list);
	return (1);
}