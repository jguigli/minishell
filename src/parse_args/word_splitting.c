/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:02:45 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:49 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_datas	*first_add_node(char *indextab, t_datas *list)
{
	t_datas	*new;

	new = my_lstnew(indextab);
	list->next = new;
	new->previous = list;
	if (new->data[0] == 34)
		new->type = TOKEN_DQUOTE;
	else if (new->data[0] == 39)
		new->type = TOKEN_SQUOTE;
	else
		new->type = TOKEN_OPT;
	new->t_token = "TOKEN_OPT";
	new->next = NULL;
	return (new);
}

static t_datas	*other_add_node(char *indextab, t_datas *current)
{
	t_datas	*new;

	new = my_lstnew(indextab);
	current->next = new;
	new->previous = current;
	new->next = NULL;
	if (new->data[0] == 34)
		new->type = TOKEN_DQUOTE;
	else if (new->data[0] == 39)
		new->type = TOKEN_SQUOTE;
	else
		new->type = TOKEN_OPT;
	new->t_token = "TOKEN_OPT";
	return (new);
}

static void	link_free(t_datas *tf_next,
	t_datas *current, char **tab, t_datas *list)
{
	if (tf_next)
	{
		current->next = tf_next;
		tf_next->previous = current;
	}
	free (tab);
	free (list->data);
	list->data = ft_strdup("");
}

t_datas	*word_splitting(t_dblist *gr_list, t_datas *list)
{
	t_datas	*current;
	t_datas	*tf_next;
	char	**tab;
	int		i;

	i = 0;
	(void)gr_list;
	list->type = TOKEN_DEL;
	tf_next = list->next;
	tab = ft_split(list->data, ' ');
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (!i)
			current = first_add_node(tab[i], list);
		else
			current = other_add_node(tab[i], current);
		i++;
	}
	link_free(tf_next, current, tab, list);
	return (current);
}
