/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:51:23 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:51:25 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_datas	*cb_loop(t_datas *list)
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

t_datas	*cb_getnext_hd(t_datas *list, t_main *main, t_flist *head)
{
	if (list->next)
		list = list->next;
	else
		return (NULL);
	if (main->node_toadd == NULL)
		main->node_toadd = ft_strdup("");
	if (list->type == 35 || list->type == 36 || list->type == 37)
		insert_node(list->data, main->node_toadd, &head);
	else
	{
		while (list && (list->type != 35 && list->type != 36
				&& list->type != 37))
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		insert_node(list->data, main->node_toadd, &head);
	}
	main->node_toadd = NULL;
	main->tmp = NULL;
	list = cb_loop(list);
	return (list);
}

t_flist	*get_head(t_flist *head)
{
	if (head->next && head->next->nb_heredoc > 0)
		head = head->next;
	else
	{
		head = head->next;
		while (head->nb_heredoc == 0)
			head = head->next;
	}
	return (head);
}

int	cb_mainloop(t_flist *head, t_main *main, t_datas *list, t_flist *head2)
{
	while (main->i < head->nb_heredoc && list
		&& main->k < main->tota_heredoc && main->sigintos == 0)
	{
		main->fi = fork();
		if (main->fi < 0)
			return (error_msgs(errno, "Fork failed"), -200);
		manage_sig_in_forks(main->fi, main);
		if (main->fi == 0)
			cb_child_process(list, head, main, head2);
		if (waiting_child_hd(main->fi, main, main->k,
				main->tota_heredoc) == -30)
			return (-200);
		main->node_toadd = cb_get_hdstring(main, list, head);
		list = cb_getnext_hd(list, main, head);
		increment_i_k(&main->i, &main->k);
		if (main->i == head->nb_heredoc && main->k != main->tota_heredoc)
		{
			main->i = 0;
			head = get_head(head);
			list = head->process->first;
		}
		else if (main->i == head->nb_heredoc && main->k == main->tota_heredoc)
			break ;
	}
	return (0);
}

int	multiple_block_p(t_flist **gr_list, int totalhd, t_main *main)
{
	t_datas	*list;
	t_flist	*head;
	t_flist	*head2;

	(void)totalhd;
	head = *gr_list;
	head2 = *gr_list;
	head = complexcmd_gethd(head);
	list = head->process->first;
	list = gettohd(list);
	if (cb_mainloop(head, main, list, head2) == -200)
		return (-200);
	return (0);
}
