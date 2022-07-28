/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:07:09 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:29:32 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	create_str(t_dblist **list, char *e, char *str)
{
	t_dblist	*l;

	l = *list;
	if (l->in->tt != 1)
	{
		if (l->in->sp > 0)
		{
			l->in->m = l->in->sp;
			l->in->sp = 0;
		}
		str = ft_substr(e, l->in->m, (l->in->k - l->in->m));
		l->in->pos++;
		create_token_list(l, str, l->in->tt);
	}
	return (0);
}

int	increment_or_no(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if ((l->in->gch[(unsigned int)e[l->in->k]] != CHR_EOF
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_PIPE
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_DQUOTE
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_SQUOTE
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_RRED
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_LRED
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_WORD
			&& l->in->gch[(unsigned int)e[l->in->k]] != CHR_BANG
			&& l->in->gch[(unsigned int)e[l->in->k - 1]] != CHR_EOF)
		&& l->in->tt != 6 && l->in->tt != 7)
	{
		l->in->k++;
	}
	return (l->in->k);
}

int	first_checks(t_dblist **list, char *e)
{
	t_dblist	*l;

	l = *list;
	if (check_nonprintablechar(e) == 0)
		return (0);
	if (e[0] == '\0')
		return (0);
	if (check_fichar(&l, e) == 0)
		return (0);
	if (check_start_ws(&l, e) == 0)
		return (0);
	return (1);
}

int	main_loop(t_dblist **list, char *e, char *str)
{
	t_dblist	*l;

	l = *list;
	while (e[l->in->k])
	{
		l->in->tt = l->in->gtt[l->in->gch[(unsigned int)e[l->in->k]]];
		while (l->in->grul[l->in->tt][l->in->gch[(unsigned int)e[l->in->k]]]
		&& (l->in->dq == 1 && l->in->sq == 1))
		{
			if (is_dquoted(&l, e) == 0)
				return (0);
			if (is_squoted(&l, e) == 0)
				return (0);
			if (l->in->sq == 0 || l->in->dq == 0)
			{
				if (manage_quote(&l, e) == 1)
					break ;
			}
			else
				l->in->k++;
		}
		tok_creation(l, e, str);
		l->in->m = l->in->k;
	}
	return (1);
}

t_dblist	*get_tokens(char *e)
{
	t_dblist	*l;
	char		*str;

	str = NULL;
	l = init_linked_list();
	if (first_checks(&l, e) == 0)
	{
		free_dblist(l);
		return (NULL);
	}
	if (main_loop(&l, e, str) == 0)
	{
		free_dblist(l);
		return (NULL);
	}
	if (p_tok(l) == NULL)
	{
		free_dblist(l);
		return (NULL);
	}
	return (l);
}
