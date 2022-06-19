#include "../../includes/minishell.h"

char	*ft_strjoin_path(char *s1, char *s2)
{
	char		*cat;
	int			length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * (length + 1));
	if (!cat)
		return (NULL);
	cat[0] = '\0';
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	cat[length] = '\0';
	return (cat);
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
	(void)exec;
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
