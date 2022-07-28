/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:59:39 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:59:40 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_datas	*free_first_zero(t_dblist *gr_list, t_datas *current, int *incr)
{
	t_datas	*stock_curr;

	while (current && current->data[0] == '\0' && current->type != 13
		&& current->type != 12)
	{
		stock_curr = current;
		if (current->next)
		{
			current = current->next;
			*incr = 1;
		}
		else
			break ;
		free(stock_curr->data);
		free(stock_curr);
		gr_list->first = current;
	}
	return (current);
}

static t_datas	*free_other_zero_next(t_datas *current, int *incr)
{
	t_datas	*stock_curr;
	t_datas	*stock_prev;
	t_datas	*stock_next;

	stock_next = current->next;
	stock_curr = current;
	stock_prev = current->previous;
	current = current->next;
	*incr = 1;
	free(stock_curr->data);
	free (stock_curr);
	stock_prev->next = stock_next;
	stock_next->previous = stock_prev;
	return (current);
}

static void	free_other_zero_nonext(t_datas *current)
{
	t_datas	*stock_prev;

	stock_prev = current->previous;
	stock_prev->next = NULL;
	free(current->data);
	free (current);
}

static t_datas	*free_other_zero(t_datas *current, int *incr)
{
	if (current && current->data[0] == '\0' && current->type != 12
		&& current->type != 13)
	{
		if (current->next && current->data[0] == '\0')
			current = free_other_zero_next(current, incr);
		if (current->next == NULL && current->data[0] == '\0')
		{
			free_other_zero_nonext(current);
			return (NULL);
		}
	}
	return (current);
}

void	delete_nodes_after_expansion(t_dblist **l)
{
	t_datas		*current;
	t_dblist	*list;
	int			incr;

	incr = 0;
	list = *l;
	current = list->first;
	current = free_first_zero(list, current, &incr);
	if (current->next && incr == 0)
		current = current->next;
	else if (current->next == NULL)
		return ;
	incr = 0;
	while (current)
	{
		current = free_other_zero(current, &incr);
		if (!current)
			break ;
		if (incr == 0)
			current = current->next;
		incr = 0;
	}
}
