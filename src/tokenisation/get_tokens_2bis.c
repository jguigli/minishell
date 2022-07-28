/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_2bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:24:20 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:24:33 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	squoted_loop(t_dblist *l, char *e)
{
	while (l->in->sq == 1)
	{
		if (l->in->gch[(unsigned int)e[l->in->k]] == CHR_EOF)
		{
			syntax_err(SYNTAX_ERR, "\'");
			return (0);
		}
		if (e[l->in->k] == '\'')
		{
			l->in->sq = 0;
			break ;
		}
		l->in->k++;
	}
	return (l->in->k);
}
