/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_residus_bis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:51:47 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:51:50 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	increment_i_k(int *i, int *k)
{
	(*i)++;
	(*k)++;
}

t_datas	*next_exist(t_datas *current, char *node_toadd, t_flist *copy_head)
{
	t_datas	*tmp_tonext;
	t_datas	*new;

	tmp_tonext = current->next;
	new = my_lstnew(node_toadd);
	new->previous = current;
	current->next = new;
	new->pos = current->pos++;
	new->next = tmp_tonext;
	tmp_tonext->previous = new;
	copy_head->process->number ++;
	new->type = 39;
	new->t_token = "TOKEN_HEREDOC_STRING";
	return (current);
}

t_datas	*next_dontexist(t_datas *current, char *node_toadd, t_flist *copy_head)
{
	t_datas	*new;

	new = my_lstnew(node_toadd);
	new->previous = current;
	current->next = new;
	new->next = NULL;
	copy_head->process->last = new;
	copy_head->process->number++;
	new->type = 39;
	new->pos = current->pos++;
	new->t_token = "TOKEN_HEREDOC_STRING";
	return (current);
}

void	insert_node(char *repere, char *node_toadd, t_flist **head)
{
	t_datas	*current;
	t_flist	*copy_head;

	current = (*head)->process->first;
	copy_head = *head;
	current = insert_lopp(current, repere);
	if (current->next)
		current = next_exist(current, node_toadd, copy_head);
	else
		current = next_dontexist(current, node_toadd, copy_head);
}
