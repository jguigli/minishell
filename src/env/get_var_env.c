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

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
}

int	search_var_tab(char *var, char **tab)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (!var || !tab)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '=' && tab[i][j])
			j++;
		while (var[z] != '=' && var[z])
			z++;
		if (j == z)
		{
			if (!ft_strncmp(var, tab[i], j))
				return (1);
		}
		i++;
	}
	return (0);
}

int	search_var_tab_plus(char *var, char **tab)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (!var || !tab)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '=' && tab[i][j])
			j++;
		while (var[z] != '+' && var[z])
			z++;
		if (j == z)
		{
			if (!ft_strncmp(var, tab[i], j))
				return (1);
		}
		i++;
	}
	return (0);
}

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
				return (ft_strdup(&env[i][j + 1]));
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
	char	**tab;

	i = -1;
	if (!env)
		return (NULL);
	if (!path)
		return (env);
	tab = dup_env_tab(env);
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j] != '=' && tab[i][j])
			j++;
		if (!ft_strncmp(var, env[i], j))
		{
			str = ft_substr(env[i], 0, j + 1);
			str = ft_strjoin(str, path);
			free (tab[i]);
			tab[i] = str;
		}
	}
	return (free_char_tab(env), tab);
}
