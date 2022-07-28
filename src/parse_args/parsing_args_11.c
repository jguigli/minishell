/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_11.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:51:07 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:51:13 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_tot_heredoc(t_flist **list)
{
	t_flist	*gr_list;
	int		tota_heredoc;

	tota_heredoc = 0;
	gr_list = *list;
	while (gr_list)
	{
		if (gr_list->nb_heredoc > 0)
			tota_heredoc += gr_list->nb_heredoc;
		if (gr_list->next)
			gr_list = gr_list->next;
		else
			break ;
	}
	return (tota_heredoc);
}

int	check_if_redir_only(t_datas *data, t_flist **li)
{
	t_flist	*list;

	list = *li;
	(void)data;
	while (list)
	{
		if ((list->process->first && my_lstsize_dblist(list->process) == 2
				&& (list->process->first->next->type == 6
					|| list->process->first->next->type == 7)))
		{
			syntax_err(SYNTAX_ERR, "`newline`");
			return (0);
		}
		list = list->next;
	}
	return (1);
}

t_datas	*cr_blocks(t_datas *data, t_flist *finli, t_datas *to_free)
{
	while (data->type != 11)
	{
		create_grtoken((finli)->process, data->data, data->t_token, data->type);
		to_free = data;
		if (data->next != NULL)
		{
			data = data->next;
			free(to_free);
		}
		else
		{
			free(to_free);
			return (NULL);
		}
	}
	return (data);
}

t_datas	*get_next_andfree(t_datas *data, t_datas *to_free)
{
	data = data->next;
	free(to_free->data);
	free(to_free);
	return (data);
}

t_flist	*get_processes(t_dblist *list)
{
	t_flist		*finli;
	t_flist		*finli_cur;
	t_flist		*head;
	t_datas		*to_free;

	finli = init_struct_flist();
	head = finli;
	while (list->first)
	{
		list->first = cr_blocks(list->first, finli, to_free);
		if (list->first == NULL)
			break ;
		if (list->first->next != NULL)
		{
			to_free = list->first;
			list->first = get_next_andfree(list->first, to_free);
			finli_cur = init_struct_flist();
			my_lstadd_back(&finli, finli_cur);
			finli = finli_cur;
		}
		else
			return (free(to_free), head);
	}
	return (head);
}
