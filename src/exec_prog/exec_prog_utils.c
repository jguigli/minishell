#include "../../includes/minishell.h"

// static int	count_quote(char *argv)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (argv[++i])
// 	{
// 		if (argv[i] == 39)
// 			count++;
// 	}
// 	return (count);
// }

// char	**split_arg(char *argv)
// {
// 	int		count;
// 	char	**tab;

// 	count = count_quote(argv);
// 	if (count == 2)
// 		tab = ft_split_cmd_quote(argv);
// 	else
// 		tab = ft_split(argv, ' ');
// 	return (tab);
// }

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
		if (access(path_cmd, 0) == 0)
			return (path_cmd);
		free(path_cmd);
		path++;
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
		printf("la 1 DUP\n");
		//free_path(&exec);
		//write_error_path(ERROR_DUP, &exec);
	}
	if (dup2(second, STDOUT_FILENO) < 0)
	{
		printf("la 2 DUP\n");
		//free_path(&exec);
		//write_error_path(ERROR_DUP, &exec);
	}
}