/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:59:03 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:59:05 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*case_g_status(int *i, char *str)
{
	char	*temp;

	temp = ft_itoa(g_status);
	str = ft_strjoin(str, temp);
	free(temp);
	(*i)++;
	return (str);
}

char	*case_dolafterdol(int *i, char *str)
{
	str = ft_strjoin(str, "$");
	(*i)++;
	return (str);
}

char	*case_nodol_noquote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	j = *i;
	while (data[*i] != '$' && data[*i] != 34 && data[*i] != 39 && data[*i])
		(*i)++;
	if (*i != j)
	{
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
		free(temp);
	}
	return (str);
}

static char	*case_dol_noalnum(char *data, int *i, int *j, char *str)
{
	char	*temp;

	while (!ft_isalnum(data[*i]) && data[*i] != 34
		&& data[*i] != 39 && data[*i] != '$' && data[*i])
		(*i)++;
	temp = ft_substr(data, *j, *i - *j);
	str = ft_strjoin(str, "$");
	str = ft_strjoin(str, temp);
	free(temp);
	(*i)--;
	return (str);
}

char	*case_dol_noquote(char *data, char **env, int *i, char *str)
{
	char	*temp;
	char	*temp2;
	int		j;

	(*i)++;
	j = *i;
	if (!ft_isalnum(data[*i]) && data[*i] != 34 && data[*i] != 39
		&& data[*i] != '_')
		return (case_dol_noalnum(data, i, &j, str));
	while ((data[*i] == '_' || ft_isalnum(data[*i])) && data[*i])
		(*i)++;
	temp = ft_substr(data, j, *i - j);
	temp2 = search_in_env_var(temp, env);
	free(temp);
	if (temp2)
	{
		str = ft_strjoin(str, temp2);
		free(temp2);
	}
	(*i)--;
	return (str);
}
