/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:02:02 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/07 13:41:00 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_strchr(const char *s, int c)
{
    char            sent;
    unsigned char    character;
    size_t            i;

    sent = (char)s;
    character = (unsigned char)c;
    i = 1;
    while (i <= ft_strlen(s))
    {
        if (sent[i] == character)
            return (2);
        i ++;
    }
    return (0);
}
