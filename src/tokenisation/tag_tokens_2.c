/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_tokens_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:27:27 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:27:30 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_datas	*heredoking(t_datas *tag, t_dblist *list)
{
	is_heredoc(tag, list);
	tag = tag->next;
	list->in->incr = 1;
	if (tag->type == 13)
		is_dq_delim(tag, list, 1);
	else if (tag->type == 12)
		is_sq_delim(tag, list, 1);
	else
		is_simple_delim(tag, list, 1);
	if (tag->next != NULL && list->in->incr == 0)
	{
		tag = tag->next;
		list->in->incr = 1;
	}
	else
		return (NULL);
	if (tag->type == 5)
	{
		tag = word_after_delim(tag, list);
		if (tag == NULL)
			return (NULL);
	}
	return (tag);
}

t_datas	*lred_heredoc(t_datas *tag, t_dblist *list)
{
	is_heredoc(tag, list);
	list->in->incr = 0;
	if (tag->next)
		tag = tag->next;
	else
		return (NULL);
	if (tag->type == 13)
		is_dq_delim(tag, list, 1);
	else if (tag->type == 12)
		is_sq_delim(tag, list, 1);
	else
		is_simple_delim(tag, list, 1);
	return (tag);
}

void	check_previous(t_datas *tag, t_dblist *list)
{
	if (tag->previous->type == 6 || tag->previous->type == 7
		|| tag->previous->type == 33 || tag->previous->type == 38)
		is_file(tag, list, 1);
}

t_datas	*not_heredoking(t_datas *tag, t_dblist *list)
{
	if (tag->next != NULL)
	{
		tag = tag->next;
		is_file(tag, list, 1);
	}
	if (tag->next != NULL)
	{
		tag = tag->next;
		if (tag->type == 5)
			is_cmd(tag);
		if (tag->next != NULL)
		{
			tag = tag->next;
			list->in->incr = 1;
		}
		check_previous(tag, list);
	}
	if (tag->next == NULL)
		return (NULL);
	if (list->in->incr == 0)
		tag = tag->next;
	list->in->incr = 0;
	return (tag);
}

t_datas	*redir_after_hd(t_datas *tag, t_dblist *list)
{
	if (tag->next == NULL)
		return (NULL);
	else if (tag->type == 7 && tag->length == 2)
	{
		tag = lred_heredoc(tag, list);
		if (tag == NULL)
			return (NULL);
	}
	else if (tag->type == 6 && tag->length == 2)
	{
		is_rred_append(tag, list, 0);
		tag = tag->next;
		is_file(tag, list, 1);
	}
	else
	{
		tag = tag->next;
		is_file(tag, list, 1);
	}
	return (tag);
}
