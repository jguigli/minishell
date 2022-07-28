/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:19 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:28:21 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	check_fichar(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if ((l->in->gch[(unsigned int)e[0]] == CHR_DIEZ
			|| l->in->gch[(unsigned int)e[0]] == CHR_COLON
			|| l->in->gch[(unsigned int)e[0]] == CHR_BANG)
		&& l->in->gch[(unsigned int)e[1]] == CHR_EOF)
	{
		if (l->in->gch[(unsigned int)e[0]] == CHR_BANG
			&& l->in->gch[(unsigned int)e[1]] == CHR_EOF)
			g_status = 1;
		g_status = 0;
		return (0);
	}
	return (1);
}

int	dquoted_loop(t_dblist *l, char *e)
{
	while (l->in->dq == 1)
	{
		if (l->in->gch[(unsigned int)e[l->in->k]] == CHR_EOF)
		{
			syntax_err(SYNTAX_ERR, "\"");
			return (0);
		}
		if (e[l->in->k] == '\"')
		{
			l->in->dq = 0;
			break ;
		}
		l->in->k++;
	}
	return (l->in->k);
}

int	is_dquoted(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if (e[l->in->k] == '\"')
	{
		l->in->dq = 1;
		l->in->k++;
		if (l->in->gch[(unsigned int)e[l->in->k]] == CHR_EOF)
		{
			syntax_err(SYNTAX_ERR, "\"");
			return (0);
		}
		l->in->k = dquoted_loop(l, e);
		if (l->in->k == 0)
			return (0);
	}
	return (1);
}
