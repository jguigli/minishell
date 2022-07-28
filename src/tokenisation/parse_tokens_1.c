/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:24:54 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:25:13 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	is_pipe(t_datas *p_list)
{
	if (p_list->type == 11)
	{
		if (p_list->length > 1)
		{
			syntax_err(SYNTAX_ERR, p_list->data);
			return (0);
		}
		if (!p_list->next)
		{
			syntax_err(SYNTAX_ERR, p_list->data);
			return (0);
		}
	}
	return (1);
}

int	is_redir(t_datas *p_list)
{
	if (p_list->type == 6 || p_list->type == 7)
	{
		if (p_list->length == 2)
		{
			if (p_list->data[1] != p_list->data[0])
			{
				syntax_err(SYNTAX_ERR, "`newline`");
				return (0);
			}
		}
		if (p_list->next && (p_list->next->type == 6
				|| p_list->next->type == 7))
		{
			syntax_err(SYNTAX_ERR, p_list->next->data);
			return (0);
		}
		if (p_list->length > 2 || (p_list->length >= 1 && !p_list->next))
		{
			syntax_err(SYNTAX_ERR, p_list->data);
			return (0);
		}
	}
	return (1);
}

int	is_dot(t_datas *p_list, t_dblist *list)
{
	if (p_list->type == 28)
	{
		if (p_list->data[1]
			&& (p_list->data[1] != '/' && p_list->data[1] != '.'))
		{
			syntax_err(SYNTAX_ERR, p_list->data);
			return (0);
		}
		if (p_list->length == 1 && my_lstsize_dblist(list) == 1)
		{
			isdir_err(DIR_ERR, p_list->data);
			g_status = 126;
			return (0);
		}
	}
	else if (p_list->type != 12 && p_list->type != 13
		&& p_list->type != 26 && p_list->type != 2)
	{
		syntax_err(SYNTAX_ERR, p_list->data);
		return (0);
	}
	return (1);
}

int	check_nodes(t_datas *p_list, t_dblist *list)
{
	if (p_list->type == 11)
	{
		if (is_pipe(p_list) == 0)
			return (0);
	}
	else if (p_list->type == 6 || p_list->type == 7)
	{
		if (is_redir(p_list) == 0)
			return (0);
	}
	else if (p_list->type == 28)
	{
		if (is_dot(p_list, list) == 0)
			return (0);
	}
	else if (p_list->type == 2 && my_lstsize_dblist(list) > 1)
	{
		error_msg_redir(p_list->data, "event not found");
		g_status = 0;
		return (0);
	}
	return (1);
}

t_dblist	*p_tok(t_dblist *list)
{
	t_datas	*p_list;

	p_list = list->first;
	if (first_char(p_list) == 0)
		return (NULL);
	while (p_list)
	{
		p_list->length = ft_strlen(p_list->data);
		if (check_nonprintablechar(p_list->data) == 0)
			return (NULL);
		if (check_if_pathname(p_list, list) == 0)
			return (NULL);
		if (check_nodes(p_list, list) == 0)
			return (NULL);
		if (p_list->next != NULL)
			p_list = p_list->next;
		else
			break ;
	}
	token_tag(list);
	return (list);
}
