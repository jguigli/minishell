/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:24:41 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:24:43 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_dblist	*cr_grfiel(t_dblist **list, char *s,
		unsigned int t, t_datas *element)
{
	t_dblist	*l;

	l = *list;
	l->first = element;
	element->data = s;
	element->type = t;
	element->t_token = l->in->types[t];
	element->next = NULL;
	element->previous = NULL;
	element->expansion = 0;
	l->last = element;
	l->number++;
	return (l);
}

t_dblist	*cr_grother_elem(t_dblist **list, char *s,
		unsigned int t, t_datas *element)
{
	t_dblist	*l;
	t_datas		*current;

	l = *list;
	current = l->first;
	while (current->next)
		current = current->next;
	current->next = element;
	element->data = s;
	element->type = t;
	element->t_token = l->in->types[t];
	element->next = NULL;
	element->expansion = 0;
	element->previous = current;
	l->last = element;
	l->number++;
	return (l);
}

void	create_grtoken(t_dblist *l, char *data, char *tokt, int type)
{
	t_datas		*element;

	(void)tokt;
	element = malloc(sizeof(t_datas));
	if (!element)
		exit(EXIT_FAILURE);
	if (!l->number)
		l = cr_grfiel(&l, data, type, element);
	else
		l = cr_grother_elem(&l, data, type, element);
}

t_flist	*my_lstlast(t_flist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	my_lstadd_back(t_flist **alst, t_flist *new)
{
	t_flist	*last;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = my_lstlast(*alst);
	last->next = new;
	new->previous = last;
	new->next = NULL;
}
