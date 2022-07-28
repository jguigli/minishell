/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:20:38 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:20:40 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**manage_env_i(void)
{
	char	**tab;
	char	*temp;
	char	*temp2;

	tab = malloc(sizeof(char *) * 5);
	if (!tab)
		return (NULL);
	temp = ft_strdup("PWD=");
	temp2 = getcwd(NULL, 0);
	temp = ft_strjoin(temp, temp2);
	tab[0] = ft_strdup("PATH=/bin");
	tab[1] = ft_strdup(temp);
	tab[2] = ft_strdup("SHLVL=1");
	tab[3] = ft_strdup("_=/usr/bin/env");
	tab[4] = 0;
	free (temp);
	free (temp2);
	return (tab);
}
