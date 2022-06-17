/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:34:45 by ael-khat          #+#    #+#             */
/*   Updated: 2022/06/03 18:34:51 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*search_in_env_var(char *var, char **env)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!var || !*env)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (j == ft_strlen(var))
		{
			if (!ft_strncmp(var, env[i], j))
				return (&env[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}

char	**set_var_in_env(char *var, char *path, char **env)
{
	int		i;
	int		j;
	char	*str;
	//char	*temp;
	char	**tab;

	i = 0;
	j = 0;
	if (!var || !env || !path)
		return (NULL);
	tab = dup_env_tab(env);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '=' && tab[i][j])
			j++;
		if (!ft_strncmp(var, env[i], j))
		{
			str = ft_substr(env[i], 0, j + 1);
			str = ft_strjoin(str, path);
			free(tab[i]);
			tab[i] = ft_strdup(str);
		}
		i++;
	}
	return (tab);
}
