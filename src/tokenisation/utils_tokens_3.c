/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:43 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:32:37 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	tok_creation(t_dblist *l, char *e, char *str)
{
	create_str(&l, e, str);
	increment_or_no(&l, e);
}

void	is_cmd(t_datas *tag)
{
	tag->t_token = "TOKEN_CMD";
	tag->type = 24;
}
