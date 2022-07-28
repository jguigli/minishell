/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manage_redir_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:18:10 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:18:50 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_datas	*delnode_nextok(t_datas *current, t_flist *list)
{
	t_datas	*stock_prev;
	t_datas	*stock_next;
	t_datas	*stock_curr;

	stock_next = current->next;
	stock_curr = current;
	stock_prev = current->previous;
	current = current->next;
	list->process->in->incr = 1;
	free(stock_curr->data);
	free (stock_curr);
	stock_prev->next = stock_next;
	stock_next->previous = stock_prev;
	return (current);
}

t_datas	*delnode_fir_empty(t_datas *current, t_flist *list)
{
	t_datas	*stock_prev;

	if (current && current->data[0] == '\0'
		&& current->type != 12 && current->type != 13)
	{
		if (current->next)
			current = delnode_nextok(current, list);
		if (current->next == NULL && current->data[0] == '\0')
		{
			stock_prev = current->previous;
			stock_prev->next = NULL;
			free(current->data);
			free (current);
			return (NULL);
		}
	}
	return (current);
}

void	delnode_mainloop(t_datas *current, t_flist *list)
{
	while (current)
	{
		current = delnode_fir_empty(current, list);
		if (current == NULL)
			break ;
		if (list->process->in->incr == 0)
			current = current->next;
		list->process->in->incr = 0;
	}
}

void	delete_node(t_flist **li)
{
	t_flist	*list;
	t_datas	*current;

	list = *li;
	while (list)
	{
		current = list->process->first;
		current = delnode_empty(current, list);
		if (current == NULL)
		{
			if (list->process->in->check == 0)
				list->process->first = NULL;
			return ;
		}
		list->process->in->check = 1;
		if (current->next && list->process->in->incr == 0)
			current = current->next;
		else if (current->next == NULL)
			break ;
		list->process->in->incr = 0;
		delnode_mainloop(current, list);
		if (!list->next)
			break ;
		list = list->next;
	}
}

t_datas	*is_rred_app(t_datas *current, t_main *main)
{
	if (output_r(current, main) != -5)
	{
		free (current->data);
		current->data = ft_strdup("");
		if (current->next && current->next->type == 21)
		{
			current = current->next;
			free (current->data);
			current->data = ft_strdup("");
		}
	}
	else
	{
		g_status = 1;
		return (NULL);
	}
	return (current);
}
