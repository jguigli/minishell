#include "../../includes/minishell.h"

int	parse_cmd(char *argument)
{
	if (argument[0] == '/')
		return (-1);
	else if (ft_strchr(argument, '/') == 2)
		return (-1);
	else if (ft_strchr(argument, '.') != 0)
		return (-1);
	else
		return (0);
}

char	*get_command(char **path, char *cmd)
{
	char	*temp;
	char	*path_cmd;

	if (!cmd)
		return (NULL);
	if (parse_cmd(cmd) == -1)
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		}
		else
			return ("KO");
	}
	else
	{
		while (*path)
		{
			if (cmd[0] == '/')
				return (NULL);
			temp = ft_strjoin_path(*path, "/");
			path_cmd = ft_strjoin(temp, cmd);
			if (access(path_cmd, 0) == 0)
				return (path_cmd);
			free(path_cmd);
			path++;
		}
	}
	return (NULL);
}

void	create_pipes(t_exec_c *exec)
{
	int	i;

	i = 0;
	while (i < exec->cmd_number - 1)
	{
		if (pipe(exec->pipe + 2 * i) < 0)
			exit(0);
		i++;
	}
}

void	close_pipes(t_exec_c *exec)
{
	int	i;

	i = 0;
	while (i < exec->pipe_number)
	{
		close(exec->pipe[i]);
		i++;
	}
}

void	manage_dup2(t_exec_c exec, int first, int second)
{
	if (dup2(first, STDIN_FILENO) < 0)
	{
		error_msgs(errno, "Fd's duplication failed");
		//free_path(&exec);
		//write_error_path(ERROR_DUP, &exec);
	}
	if (dup2(second, STDOUT_FILENO) < 0)
	{
		error_msgs(errno, "Fd's duplication failed");
		//free_path(&exec);
		//write_error_path(ERROR_DUP, &exec);
	}
}
