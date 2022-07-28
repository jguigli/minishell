/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:20:55 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:20:59 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	simpleq;
	int	doubleq;

	i = 0;
	simpleq = 0;
	doubleq = 0;
	while (str[i])
	{
		if (str[i] == 34)
			doubleq++;
		if (str[i] == 39)
			simpleq++;
		i++;
	}
	if (!(doubleq % 2) && !(simpleq % 2))
		return (1);
	else
		return (0);
}
