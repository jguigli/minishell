/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_tokens_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:27:48 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:27:50 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	is_rred_append(t_datas *tag, t_dblist *list, int choix)
{
	tag->type = 38;
	tag->t_token = "TOKEN_RRED_APPEND";
	if (choix == 1)
		list->in->incr = 0;
}

void	is_dq_delim(t_datas *tag, t_dblist *list, int choix)
{
	tag->type = 36;
	tag->t_token = "DQUOTED_DELIM";
	if (choix == 1)
		list->in->incr = 0;
}

void	is_sq_delim(t_datas *tag, t_dblist *list, int choix)
{
	tag->type = 37;
	tag->t_token = "SQUOTED_DELIM";
	if (choix == 1)
		list->in->incr = 0;
}

void	is_simple_delim(t_datas *tag, t_dblist *list, int choix)
{
	tag->type = 35;
	tag->t_token = "SIMPLE_DELIM";
	if (choix == 1)
		list->in->incr = 0;
}

t_datas	*file_or_delim(t_datas *tag, t_dblist *list)
{
	if (tag->previous->type != 33)
		is_file(tag, list, 1);
	else
	{
		if (tag->type == 13)
			is_dq_delim(tag, list, 1);
		else if (tag->type == 12)
			is_sq_delim(tag, list, 1);
		else
			is_simple_delim(tag, list, 1);
	}
	return (tag);
}
