/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:23:26 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:23:28 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **arg, char **env)
{
	int	i;

	i = 0;
	g_status = 0;
	if (!arg[1])
	{
		if (!env)
			return ;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		printf("env: too much arguments\n");
		g_status = 2;
	}
}
