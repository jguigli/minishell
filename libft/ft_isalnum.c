/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:30:27 by jguigli           #+#    #+#             */
/*   Updated: 2021/11/30 14:39:38 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_othersymbols(int c)
// {
// 	char	car;

// 	car = (char)c;
// 	if (car == '>' || car == '|' || car == '$' || car == '<' )
// 		return (1);
// 	return (0);
// }

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
