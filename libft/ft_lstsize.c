/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:08:59 by jguigli           #+#    #+#             */
/*   Updated: 2022/05/11 17:15:21 by aminaelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_dblist *lst)
{
	int		i;
	t_datas	*lstnext;

	lstnext = lst->first;
	i = 1;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	return (i);
}
