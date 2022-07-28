/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:22:58 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:23:00 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**unset_var_env(int position, char **env)
{
	size_t		i;
	char		**tab;

	if (!env)
		return (NULL);
	i = position;
	tab = dup_env_tab(env);
	while (i < ft_strlen_double(tab))
	{
		free(tab[i]);
		tab[i] = ft_strdup(env[i + 1]);
		i++;
	}
	tab[i] = 0;
	free_char_tab(env);
	return (tab);
}

char	**unset_var_export(int position, char **export)
{
	size_t		i;
	char		**tab;

	i = position;
	tab = dup_env_tab(export);
	while (i < ft_strlen_double(tab))
	{
		free(tab[i]);
		tab[i] = ft_strdup(export[i + 1]);
		i++;
	}
	tab[i] = 0;
	free_char_tab(export);
	return (tab);
}
