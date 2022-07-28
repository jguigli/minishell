/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:07:09 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/11 14:49:40 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	is_squoted(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if (e[l->in->k] == '\'')
	{
		l->in->sq = 1;
		l->in->k++;
		if (l->in->gch[(unsigned int)e[l->in->k]] == CHR_EOF)
		{
			syntax_err(SYNTAX_ERR, "\'");
			return (0);
		}
		l->in->k = squoted_loop(l, e);
		if (l->in->k == 0)
			return (0);
	}
	return (1);
}

int	is_quoted_redir(t_dblist *l, char *e)
{
	if (l->in->gch[(unsigned int)e[l->in->k + 1]] == 13
		|| (l->in->gch[(unsigned int)e[l->in->k + 1]] == 14))
	{
		l->in->k++;
		l->in->dq = 1;
		l->in->sq = 1;
		return (1);
	}
	return (0);
}

int	is_not_space(t_dblist *l, char *e)
{
	if (l->in->gch[(unsigned int)e[l->in->k + 1]] != 1)
	{
		l->in->dq = 1;
		l->in->sq = 1;
		l->in->k++;
	}
	else
	{
		l->in->k++;
		l->in->dq = 1;
		l->in->sq = 1;
		return (1);
	}
	return (0);
}

int	manage_quote(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if (is_quoted_redir(l, e) == 1)
		return (1);
	if (is_not_space(l, e) == 1)
		return (1);
	return (0);
}

int	check_start_ws(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if (l->in->gch[(unsigned int)e[l->in->k]] == CHR_SP)
	{
		while (e[l->in->k] && l->in->gch[(unsigned int)e[l->in->k]] == CHR_SP)
			l->in->k++;
		l->in->sp = l->in->k;
		if (e[l->in->k] == '\0')
			return (0);
	}
	return (1);
}
