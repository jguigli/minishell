/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:51:34 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:51:36 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_rules(t_glob_infos *tok_info)
{
	rules_for_bang(tok_info);
	rules_for_bslash(tok_info);
	rules_for_colon(tok_info);
	rules_for_coma(tok_info);
	rules_for_dash(tok_info);
	rules_for_diez(tok_info);
	rules_for_dol(tok_info);
	rules_for_dol_bis(tok_info);
	rules_for_dot(tok_info);
	rules_for_dquote(tok_info);
	rules_for_esp(tok_info);
	rules_for_lbrace(tok_info);
	rules_for_lbrace_bis(tok_info);
	rules_for_lbracket(tok_info);
	rules_for_lred(tok_info);
	rules_for_others(tok_info);
	rules_for_pipe(tok_info);
	init_rules_bis(tok_info);
}

char	*sb_get_hdstring(t_main *main, t_datas *list, t_flist *head)
{
	(void)list;
	(void)head;
	main->file = open(".hd1", O_RDONLY);
	if (main->file < 0)
	{
		error_msgs(errno, ".hd1");
		exit (EXIT_FAILURE);
	}
	main->tmp = get_next_line(main->file);
	while (main->tmp != NULL)
	{
		main->node_toadd = ft_strjoin(main->node_toadd, main->tmp);
		free(main->tmp);
		main->tmp = get_next_line(main->file);
	}
	close(main->file);
	return (main->node_toadd);
}

void	reset_main_values(t_main *main)
{
	main->fi = 0;
	main->file = 0;
	main->i = 0;
	main->node_toadd = NULL;
	main->tmp = NULL;
	main->pid = 0;
	main->tota_heredoc = 0;
	main->hd_wstatus = 0;
	main->ret = 0;
}

void	cb_reset_main_values(t_main *main)
{
	main->i = 0;
	main->k = 0;
	main->file = 0;
	main->fi = 0;
	main->tota_heredoc = 0;
	if (main->node_toadd)
		free(main->node_toadd);
	main->node_toadd = NULL;
	main->tmp = NULL;
	main->pid = 0;
	main->hd_wstatus = 0;
	main->ret = 0;
}

t_datas	*insertn_getnext_hd(t_datas *list, t_main *main, t_flist *head)
{
	if (list->next)
		list = list->next;
	else
		return (NULL);
	insert_node(list->data, main->node_toadd, &head);
	main->node_toadd = NULL;
	main->tmp = NULL;
	while (list && list->type != 33)
	{
		if (list->next)
			list = list->next;
		else
			break ;
	}
	return (list);
}
