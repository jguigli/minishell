/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:24:17 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:24:19 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	if (!first || !second)
		return (-100);
	while ((first[i] || second[i]) && first[i] == second[i])
		i++;
	return ((unsigned char)first[i] -(unsigned char)second[i]);
}
