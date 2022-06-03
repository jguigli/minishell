/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:33 by ael-khat          #+#    #+#             */
/*   Updated: 2022/06/03 18:33:56 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_copy(char **d_tab)
{
	char	**new_dtab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_dtab = malloc(sizeof(char **) * ft_strlen_double(d_tab));
	if (!new_dtab)
		return (NULL);
	while (d_tab[i])
	{
		new_dtab[i] = malloc(sizeof(char) * ft_strlen(d_tab[i]) + 1);
		new_dtab[i] = ft_strcpy(new_dtab[i], d_tab[i]);
		i++;
	}
	new_dtab[i] = 0;
	return (new_dtab);
}
