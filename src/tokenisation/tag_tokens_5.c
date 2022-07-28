/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_tokens_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:31:34 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:31:35 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	beginning(t_datas *tag, t_datas *head)
{
	if (tag->previous && (tag->previous->type == 6
			|| tag->previous->type == 7))
	{
		tag->t_token = "TOKEN_FILE";
		tag->type = 21;
	}
	else if (!tag->previous || tag->previous->type == 11
		|| tag->previous->type == 35 || tag->previous->type == 36
		|| tag->previous->type == 37 || head->type == 6 || head->type == 38)
	{
			tag->t_token = "TOKEN_CMD";
			tag->type = 24;
	}
	else
	{
		if (tag->type != 12 && tag->type != 13)
		{
			tag->t_token = "TOKEN_OPT";
			tag->type = 25;
		}
	}
	return (0);
}

void	is_option(t_datas *tag, t_dblist *list)
{
	tag->t_token = "TOKEN_OPT";
	tag->type = 25;
	list->in->incr = 0;
}

t_datas	*option_loop(t_datas *tag, t_dblist *list, int choix)
{
	while (tag->type != 6 && tag->type != 7 && tag->type != 11)
	{
		if (tag->type != 12 && tag->type != 13)
			is_option(tag, list);
		if (tag->next != NULL)
		{
			tag = tag->next;
			if (choix == 1)
				list->in->incr = 1;
		}
		else
			return (NULL);
	}
	return (tag);
}

void	heredoc_or_append(t_datas *tag, t_dblist *list)
{
	if (tag->type == 6)
	{
		list->in->incr = 0;
		if (tag->length == 2)
		{
			tag->t_token = "TOKEN_RRED_APPEND";
			tag->type = 38;
		}
	}
	if (tag->type == 7)
	{
		list->in->incr = 0;
		if (tag->length == 2)
		{
			tag->type = 33;
			tag->t_token = "TOKEN_HEREDOC";
		}
	}
}

void	is_file(t_datas *tag, t_dblist *list, int choix)
{
	tag->type = 21;
	tag->t_token = "TOKEN_FILE";
	if (choix == 1)
		list->in->incr = 0;
}
