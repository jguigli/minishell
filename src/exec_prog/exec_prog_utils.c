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

char	*ft_strjoin_path(char *s1, char *s2)
{
	static char	*cat;
	int		length;

	if (!s1)
		s1 = ft_strdup("");
	length = ft_strlen(s1) + ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * length + 1);
	if (!cat)
		return (NULL);
	cat[0] = '\0';
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	cat[length] = '\0';
	return (cat);
}

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
		printf("cmd = %s\n", cmd);
		if	(access(cmd, F_OK) == 0)
			return (cmd);
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
	printf("first = %d et second = %d\n", first, second);
	if (dup2(first, STDIN_FILENO) < 0)
	{
		printf("la 1 DUP\npidnumber = %d\nernno = %d\n", first, exec.pid_number, errno);
		printf("stdin= %d\n", STDIN_FILENO);
		perror(0);
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