/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:45 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/22 19:30:10 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sigfork(void)
{
	char	**to_launch;

	to_launch = malloc(sizeof(char *) * 2);
	to_launch[0] = ft_strdup("./a.out");
	to_launch[1] = NULL;
	execve("./a.out", to_launch, NULL);
	exit(g_status);
}

void	ft_launch_gcc(char *name)
{
	char	**to_launch;
	char	**envp;

	envp = malloc(sizeof(char *) * 2);
	envp[0] = ft_strdup
		("PATH=:/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin");
	envp[1] = NULL;
	to_launch = malloc(sizeof(char *) * 3);
	to_launch[0] = ft_strdup("/usr/bin/gcc");
	to_launch[1] = name;
	to_launch[2] = NULL;
	execve(to_launch[0], to_launch, envp);
}

void	ft_createprog(char *name)
{
	int		fd;
	char	*in_fd;
	pid_t	exec_1;
	char	*new_name;
	int		wstatus;

	fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		new_name = ft_trunc(name);
		ft_createprog(ft_strjoin(new_name, "_.c"));
	}
	in_fd = ft_strdup("int main()\n{\n\treturn (130);\n}");
	write(fd, in_fd, strlen(in_fd));
	exec_1 = fork();
	if (exec_1 == 0)
		ft_launch_gcc(name);
	else
	{
		waitpid(exec_1, &wstatus, 0);
		ft_sigfork();
	}
}

void	ft_signal(int signum)
{
	(void)signum;
	write(2, "\n", 1);
	ft_createprog("fd.c");
}

int	manage_sig_in_forks(pid_t pid, t_main *main)
{
	(void)main;
	if (pid == 0)
	{
		signal(SIGINT, &ft_signal);
		signal(SIGPIPE, &ft_signal);
		signal(SIGQUIT, SIG_DFL);
	}
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, &sig_quit_child);
	}
	return (0);
}
