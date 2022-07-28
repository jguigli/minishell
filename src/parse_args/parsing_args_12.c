/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_12.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:59:28 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:59:29 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	c_s_cmd(t_flist *gr_list, t_main *main)
{
	if (my_lstsize(gr_list) == 1)
	{
		if (simple_cmd(gr_list, main) == NULL)
		{
			free_flist(gr_list);
			return (0);
		}
	}
	else if (my_lstsize(gr_list) > 1)
	{
		if (complex_cmd(gr_list, main) == NULL)
		{
			free_flist(gr_list);
			return (0);
		}
	}
	return (1);
}

t_flist	*simple_cmd(t_flist *gr_list, t_main *main)
{
	if (check_if_redir_only(gr_list->process->first, &gr_list) == 0)
		return (NULL);
	if (simple_block_p(&gr_list, main) == -200)
	{
		reset_main_values(main);
		main->sigintos = 0;
		return (NULL);
	}
	reset_main_values(main);
	return (gr_list);
}

t_flist	*complex_cmd(t_flist *gr_list, t_main *main)
{
	if (check_if_redir_only(gr_list->process->first, &gr_list) == 0)
		return (NULL);
	main->tota_heredoc = check_tot_heredoc(&gr_list);
	if (main->tota_heredoc >= 1)
	{
		if (multiple_block_p(&gr_list, main->tota_heredoc, main) == -200)
		{
			cb_reset_main_values(main);
			main->sigintos = 0;
			return (NULL);
		}
		cb_reset_main_values(main);
	}
	return (gr_list);
}

t_flist	*parse_args(char *entry, t_main *main)
{
	t_dblist	*fin_li;
	t_flist		*gr_list;

	fin_li = get_tokens(entry);
	if (!fin_li)
		return (NULL);
	gr_list = get_processes(fin_li);
	free_dblist(fin_li);
	counting(&gr_list);
	if (c_s_cmd(gr_list, main) == 0)
		return (NULL);
	return (gr_list);
}
