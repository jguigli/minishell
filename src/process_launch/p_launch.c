#include "../../minishell.h"

int	ft_processes(char *argv[], char **paths, char *env[])
{
	int	fd[2];
	int	fi;
	int	sec;
	int	wstatus;

	if (pipe(fd) == -1)
		pers_err_msges(ERR_PIPE);
	fi = fork();
	if (fi < 0)
		error_msgs();
	if (fi == 0)
		p_child_one(fd, argv, paths, env);
	sec = fork();
	if (sec < 0)
		error_msgs();
	if (sec == 0)
		p_child_two(fd, argv, paths, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(fi, &wstatus, 0);
	waitpid(sec, &wstatus, 0);
	if (WIFEXITED (wstatus))
		return (WEXITSTATUS(wstatus));
	return (0);
}