/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:50:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 21:21:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_redir(t_datas *list, t_flist **he, int pos)
{
	t_flist	*head;

	head = *he;
	if (list->type == 6)
	{
		head->nb_rred++;
		head->pos_rred = pos;
	}
	if (list->type == 7)
	{
		head->nb_lred++ ;
		head->pos_lred = pos;
	}
}

void	count_heredoc_append_opt(t_datas *list, t_flist **he, int pos)
{
	t_flist	*head;

	head = *he;
	if (list->type == 33)
	{
		head->nb_heredoc++;
		head->pos_heredoc = pos;
	}
	if (list->type == 38)
	{
		head->pos_rred_app = pos;
		head->nb_rred_app++;
	}
	if (list->type == 25)
	{
		head->nb_options++;
		head->pos_options = pos;
	}
}

void	counting(t_flist **gr_list)
{
	t_datas	*list;
	t_flist	*head;
	int		pos;

	head = *gr_list;
	pos = 1;
	while (head)
	{
		list = head->process->first;
		while (list)
		{
			count_redir(list, &head, pos);
			count_heredoc_append_opt(list, &head, pos);
			pos++;
			if (list->next != NULL)
				list = list->next;
			else
				break ;
		}
		pos = 0;
		if (head->next != NULL)
			head = head->next;
		else
			break ;
	}
}

t_datas	*my_lstnew(char *data)
{
	t_datas	*newlist;

	newlist = ft_calloc(1, sizeof(t_datas));
	if (!newlist)
		return (NULL);
	newlist->data = data;
	newlist->t_token = NULL;
	newlist->expansion = 0;
	return (newlist);
}

t_datas	*insert_lopp(t_datas *current, char *repere)
{
	while (current)
	{
		if (ft_strcmp(repere, current->data) == 0 && (current->type == 35
				|| current->type == 36 || current->type == 37))
			return (current);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (current);
}
