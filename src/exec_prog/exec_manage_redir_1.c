/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manage_redir_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:07:59 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:08:01 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_datas	*is_lred_hd(t_datas *current, t_main *main)
{
	if (input_r(current, main) != -5)
	{
		free(current->data);
		current->data = ft_strdup("");
		if (current->next && (current->next->type == 21
				|| current->next->type == 35 || current->next->type == 36
				|| current->next->type == 37))
		{
			current = current->next;
			free (current->data);
			current->data = ft_strdup("");
		}
		if (current->next && current->next->type == 39)
		{
			current = current->next;
			free (current->data);
			current->data = ft_strdup("");
		}
	}
	else
	{
		g_status = 1;
		return (NULL);
	}
	return (current);
}

t_datas	*change_fds(t_datas *current, t_main *main)
{
	if (current->type == 6 || current->type == 38)
	{
		current = is_rred_app(current, main);
		if (current == NULL)
			return (NULL);
	}
	else if (current->type == 7 || current->type == 33)
	{
		current = is_lred_hd(current, main);
		if (current == NULL)
			return (NULL);
	}
	return (current);
}

int	manage_redirections(t_flist **li, t_main *main)
{
	t_flist	*list;
	int		inp_redir;
	int		outp_redir;
	t_datas	*current;

	list = *li;
	inp_redir = list->nb_heredoc + list->nb_lred;
	outp_redir = list->nb_rred_app + list->nb_rred;
	current = list->process->first;
	while (current)
	{
		current = change_fds(current, main);
		if (current == NULL)
			return (-5);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	delete_node(&list);
	return (0);
}
