/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_expansion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:48:56 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:55:28 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*if_is_no_quoted(char *str, char *rep, int i, int j)
{
	char	*temp;

	temp = ft_substr(str, j, i - j);
	rep = ft_strjoin(rep, temp);
	free(temp);
	return (rep);
}

char	*if_is_dquoted(char *str, char *rep, int *i, int j)
{
	char	*temp;

	(*i)++;
	j = *i;
	while (str[*i] != '\"' && str[*i])
		(*i)++;
	temp = ft_substr(str, j, *i - j);
	rep = ft_strjoin(rep, temp);
	free(temp);
	return (rep);
}

char	*if_is_squoted(char *str, char *rep, int *i, int j)
{
	char	*temp;

	(*i)++;
	j = *i;
	while (str[*i] != '\'' && str[*i])
		(*i)++;
	temp = ft_substr(str, j, *i - j);
	rep = ft_strjoin(rep, temp);
	free(temp);
	return (rep);
}

char	*if_is_no_dol(char *str, char *rep, int i, int j)
{
	char	*temp;

	temp = ft_substr(str, j, i - j);
	rep = ft_strjoin(rep, temp);
	free(temp);
	return (rep);
}

char	*if_is_dol(char *str, char *rep, int *i, char **env)
{
	char	*temp;
	char	*temp2;
	int		j;

	(*i)++;
	j = *i;
	while (ft_isalnum(str[*i]) && str[*i])
		(*i)++;
	temp = ft_substr(str, j, *i - j);
	temp2 = search_in_env_var(temp, env);
	free (temp);
	if (temp2)
	{
		rep = ft_strjoin(rep, temp2);
		free (temp2);
	}
	return (rep);
}
