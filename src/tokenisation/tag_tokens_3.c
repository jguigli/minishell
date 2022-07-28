/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_tokens_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:06 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:28:09 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_datas	*op_is_redir_or_pipe(t_datas *tag, t_dblist *list)
{
	if (tag->type == 6 || tag->type == 7)
	{
		heredoc_or_append(tag, list);
		if (tag->next == NULL)
			return (NULL);
		if (list->in->incr == 0)
		{
			tag = tag->next;
			list->in->incr = 1;
		}
		file_or_delim(tag, list);
		if (!tag->next)
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

t_datas	*after_word(t_datas *tag, t_dblist *list)
{
	if (tag->next != NULL)
	{
		tag = tag->next;
		list->in->incr = 1;
		tag = option_loop(tag, list, 1);
		if (tag == NULL)
			return (tag);
		tag = op_is_redir_or_pipe(tag, list);
		if (tag == NULL)
			return (NULL);
	}
	return (tag);
}

t_datas	*is_word(t_datas *tag, t_dblist *list, t_datas *head)
{
	beginning(tag, head);
	tag = after_word(tag, list);
	if (tag == NULL)
		return (NULL);
	return (tag);
}

void	is_heredoc(t_datas *tag, t_dblist *list)
{
	(void)list;
	tag->t_token = "TOKEN_HEREDOC";
	tag->type = 33;
}

t_datas	*word_after_delim(t_datas *tag, t_dblist *list)
{
	tag->t_token = "TOKEN_CMD";
	tag->type = 24;
	list->in->incr = 0;
	if (tag->next != NULL)
		tag = tag->next;
	else
		return (NULL);
	return (tag);
}
