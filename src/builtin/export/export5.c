/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:22:30 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:22:32 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**dup_env_tab_export(char **env)
{
	int		i;
	char	**tab;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i++] = 0;
	tab[i] = 0;
	free_char_tab(env);
	return (tab);
}

char	*ft_dup_without_plus(char *arg)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	str = NULL;
	temp = NULL;
	while (arg[i] != '+')
		i++;
	str = ft_substr(arg, 0, i);
	i++;
	j = i;
	while (arg[i])
		i++;
	temp = ft_substr(arg, j, i - j);
	str = ft_strjoin(str, temp);
	free (temp);
	return (str);
}

char	*ft_dup_plus(char *arg, char *line)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	str = NULL;
	temp = NULL;
	str = ft_strdup(line);
	while (arg[i] != '=')
		i++;
	j = ++i;
	while (arg[i])
		i++;
	temp = ft_substr(arg, j, i - j);
	str = ft_strjoin(str, temp);
	free (temp);
	free (line);
	return (str);
}
