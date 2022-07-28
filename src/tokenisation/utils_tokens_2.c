/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:25:27 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:25:30 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	my_lstsize(t_flist *lst)
{
	int		i;
	t_flist	*lstnext;

	lstnext = lst;
	i = 0;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	return (i);
}

int	my_lstsize_dblist(t_dblist *lst)
{
	int		i;
	t_datas	*lstnext;

	lstnext = lst->first;
	i = 0;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	return (i);
}

t_dblist	*cr_first_elem(t_dblist **list, char *s,
		unsigned int t, t_datas *element)
{
	t_dblist	*l;

	l = *list;
	l->first = element;
	element->data = s;
	element->t_token = NULL;
	element->type = t;
	element->t_token = l->in->types[t];
	element->next = NULL;
	element->expansion = 0;
	element->previous = NULL;
	l->last = element;
	l->number++;
	return (l);
}

t_dblist	*cr_other_elem(t_dblist **list, char *s,
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
	element->t_token = l->in->types[t];
	element->type = t;
	element->next = NULL;
	element->expansion = 0;
	element->previous = current;
	l->last = element;
	l->number++;
	return (l);
}

void	create_token_list(t_dblist *l, char *s, unsigned int t)
{
	t_datas		*element;

	element = ft_calloc(1, sizeof(t_datas));
	if (!element)
		exit(EXIT_FAILURE);
	if (l->number == 0)
	{
		l = cr_first_elem(&l, s, t, element);
	}
	else
		l = cr_other_elem(&l, s, t, element);
}
