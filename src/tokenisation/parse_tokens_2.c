/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:24:02 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:24:12 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	check_if_pathname(t_datas *data, t_dblist *list)
{
	if (my_lstsize_dblist(list) == 1 && data->type == 27 && data->length >= 1
		&& list->in->gch[(unsigned int)data->data[1]] != CHR_WORD)
	{
		isdir_err(DIR_ERR, data->data);
		return (0);
	}
	if (data->type == 28 && data->length == 1 && my_lstsize_dblist(list) == 1)
	{
		syntax_err("filename argument required", data->data);
		printf("%s: usage: %s filename [arguments]\n", data->data, data->data);
		g_status = 2;
		return (0);
	}
	return (1);
}

int	first_char(t_datas *p_list)
{
	if (p_list->type != 5 && p_list->type != 26 && p_list->type != 28
		&& p_list->type != 45 && p_list->type != 10 && p_list->type != 53
		&& p_list->type != 27 && p_list->type != 13 && p_list->type != 12
		&& p_list->type != 6 && p_list->type != 7 && p_list->type != 2
		&& p_list->type != 31)
	{
		syntax_err(SYNTAX_ERR, p_list->data);
		return (0);
	}
	return (1);
}

int	check_nonprintablechar(char *p_list)
{
	int	i;

	i = 0;
	while (p_list[i])
	{
		if (p_list[i] < 0 || p_list[i] > 127)
		{
			syntax_err(SYNTAX_ERR, p_list);
			return (0);
		}
		i++;
	}
	return (1);
}
