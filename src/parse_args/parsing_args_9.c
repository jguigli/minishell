/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:02:36 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 21:24:38 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	sb_main_loop(t_flist *head, t_main *main, t_datas *list, t_flist *head2)
{
	while (main->i < head->nb_heredoc && list && main->sigintos == 0)
	{
		main->fi = fork();
		if (main->fi < 0)
			return (error_msgs(errno, "Fork failed"), -200);
		manage_sig_in_forks(main->fi, main);
		if (main->fi == 0)
			go_heredoc(list->next, head, main, head2);
		else
		{
			if (waiting_child_hd(main->fi, main, main->i,
					head->nb_heredoc) == -30)
				return (-200);
			manage_signal();
			main->node_toadd = sb_get_hdstring(main, list, head);
			if (main->node_toadd == NULL)
				main->node_toadd = ft_strdup("");
			list = insertn_getnext_hd(list, main, head);
			main->i++;
			main->fi = -5000;
		}
	}
	return (0);
}

int	simple_block_p(t_flist **gr_list, t_main *main)
{
	t_datas	*list;
	t_flist	*head;
	t_flist	*head2;

	list = (*gr_list)->process->first;
	head = *gr_list;
	head2 = *gr_list;
	if (head->nb_heredoc >= 1)
	{
		list = gettohd(list);
		if (sb_main_loop(head, main, list, head2) == -200)
			return (-200);
	}
	return (0);
}

t_flist	*complexcmd_gethd(t_flist *head)
{
	while (head->nb_heredoc == 0)
	{
		if (head->next)
			head = head->next;
		else
			break ;
	}
	return (head);
}

void	cb_child_process(t_datas *list, t_flist *head,
			t_main *main, t_flist *head2)
{
	if (list->next->type == 35 || list->next->type == 36
		|| list->next->type == 37)
		manage_one_redir(list->next, head, head2, main);
	else
	{
		while (list && list->type != 33)
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		manage_one_redir(list->next, head, head2, main);
	}
	exit(EXIT_SUCCESS);
}

char	*cb_get_hdstring(t_main *main, t_datas *list, t_flist *head)
{
	(void)list;
	(void)head;
	main->file = open(".hd1", O_RDONLY);
	if (main->file < 0)
	{
		error_msgs(errno, "Temporary file failed");
		exit (EXIT_FAILURE);
	}
	main->tmp = get_next_line(main->file);
	while (main->tmp != NULL)
	{
		main->node_toadd = ft_strjoin(main->node_toadd, main->tmp);
		free(main->tmp);
		main->tmp = get_next_line(main->file);
	}
	if (main->node_toadd == NULL)
		main->node_toadd = ft_strdup("");
	close(main->file);
	return (main->node_toadd);
}
