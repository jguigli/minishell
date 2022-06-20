/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:36:48 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/02 18:10:24 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*catech;
	int		length;

	length = 0;
	catech = NULL;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	catech = (char *)malloc(sizeof(char) * (length + 1));
	if (!catech)
		return (NULL);
	catech[0] = '\0';
	catech = ft_strcat(catech, s1);
	catech = ft_strcat(catech, s2);
	catech[length] = '\0';
	free(s1);
	return (catech);
}
