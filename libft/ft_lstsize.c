/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:08:59 by jguigli           #+#    #+#             */
/*   Updated: 2022/05/07 11:16:55 by aminaelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lstnext;

	lstnext = lst;
	i = 0;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	return (i);
}
