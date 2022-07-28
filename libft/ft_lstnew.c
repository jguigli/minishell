/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:53:01 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/06 11:33:56 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flist	*ft_lstnew(t_dblist *content)
{
	t_flist	*newlist;

	newlist = (t_flist *)malloc(sizeof(t_flist));
	if (!newlist)
		return (NULL);
	newlist->process = content;
	newlist->next = NULL;
	return (newlist);
}
