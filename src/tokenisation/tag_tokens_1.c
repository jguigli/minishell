/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_tokens_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:25:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:26:31 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_datas	*is_lred(t_datas *tag, t_dblist *list, t_datas *head)
{
	(void)head;
	if (tag->length == 2)
		tag = heredoking(tag, list);
	else
		tag = not_heredoking(tag, list);
	if (tag == NULL)
		return (NULL);
	tag = option_loop(tag, list, 0);
	if (tag == NULL)
		return (NULL);
	if (tag->type == 6 || tag->type == 7)
	{
		tag = redir_after_hd(tag, list);
		if (tag == NULL)
			return (NULL);
	}
	else if (tag->type == 11)
	{
		list->in->incr = 0;
		if (tag->next == NULL)
			return (NULL);
	}
	return (tag);
}

t_datas	*is_rred(t_datas *tag, t_dblist *list)
{
	if (tag->length == 2)
	{
		tag->t_token = "TOKEN_RRED_APPEND";
		tag->type = 38;
	}
	if (tag->next)
	{
		tag = tag->next;
		list->in->incr = 1;
	}
	else
		return (NULL);
	tag->t_token = "TOKEN_FILE";
	tag->type = 21;
	list->in->incr = 0;
	return (tag);
}

t_datas	*is_redirection(t_datas *tag, t_dblist *list, t_datas *head)
{
	if (tag->type == 7)
	{
		tag = is_lred(tag, list, head);
		if (tag == NULL)
			return (NULL);
	}
	if (tag->type == 6)
	{
		tag = is_rred(tag, list);
		if (tag == NULL)
			return (NULL);
	}
	return (tag);
}

t_datas	*making_tags(t_datas *tag, t_dblist *list, t_datas *head)
{
	if (tag->type == 5)
	{
		tag = is_word(tag, list, head);
		if (tag == NULL)
			return (NULL);
	}
	if (tag->type == 7 || tag->type == 6)
	{
		tag = is_redirection(tag, list, head);
		if (tag == NULL)
			return (NULL);
	}
	return (tag);
}

t_dblist	*token_tag(t_dblist *list)
{
	t_datas	*tag;
	t_datas	*head;

	tag = list->first;
	head = list->first;
	while (tag)
	{
		list->in->incr = 0;
		tag = making_tags(tag, list, head);
		if (tag == NULL)
			break ;
		if (tag->next != NULL && list->in->incr == 0)
		{
			tag = tag->next;
			list->in->incr = 1;
		}
		else
			break ;
	}
	return (list);
}
