/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:51:58 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 21:24:17 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	waiting_child_hd(pid_t fi, t_main *main, int i, int tothd)
{
	main->hd_wstatus = 0;
	if (waitpid(fi, &(main->hd_wstatus), 0) == -1)
		perror("wait() error");
	if (WIFEXITED(main->hd_wstatus) > 0)
	{
		if (check_exitstatus(WEXITSTATUS(main->hd_wstatus),
				i, tothd, main) == -30)
			return (-30);
	}
	if (WIFSTOPPED(main->hd_wstatus))
		g_status = main->hd_wstatus;
	return (g_status);
}

int	get_signal(t_main *main, int wstatus, int pid, int tot_pid)
{
	(void)wstatus;
	if (WIFSIGNALED(main->exec_wstatus) > 0)
	{
		if (WTERMSIG(main->exec_wstatus) == 3)
			g_status = WTERMSIG(main->exec_wstatus) + 128;
		if (WTERMSIG(main->exec_wstatus) == 2 && pid == tot_pid - 1)
			g_status = WTERMSIG(main->exec_wstatus) + 128;
		if (WTERMSIG(main->exec_wstatus) == 2 && pid < tot_pid)
			write(2, "\n", 1);
		if (WTERMSIG(main->exec_wstatus) == 13)
		{
			if (pid != tot_pid - 1)
			{
				manage_signal();
				return (4);
			}
			closing(main);
			close(0);
			close(1);
			ft_free(main);
		}
		manage_signal();
		return (-20);
	}
	return (0);
}

int	waiting_child_exec(pid_t fi, t_main *main, int pid, int tot_pid)
{
	if (waitpid(fi, &main->exec_wstatus, 0) == -1)
	{
		perror("wait() error");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(main->exec_wstatus) > 0)
		g_status = WEXITSTATUS(main->exec_wstatus);
	if (get_signal(main, main->exec_wstatus, pid, tot_pid) == -20)
	{
		closing_bis(main);
		manage_signal();
		return (-20);
	}
	manage_signal();
	return (g_status);
}

t_datas	*gettohd(t_datas *list)
{
	while (list && list->type != 33)
	{
		if (list->next)
			list = list->next;
		else
			break ;
	}
	return (list);
}

void	go_heredoc(t_datas *list, t_flist *head, t_main *main, t_flist *head2)
{
	manage_one_redir(list, head, head2, main);
	exit(EXIT_SUCCESS);
}
