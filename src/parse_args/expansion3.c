/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:04:25 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:04:26 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*add_char_around(char *s1, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 3));
	if (!str)
		return (NULL);
	str[0] = c;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = c;
	str[++j] = '\0';
	free (s1);
	return (str);
}

char	*manage_dquote(char *data, char **env, int *i, char *str)
{
	char	*temp;

	(*i)++;
	if (data[*i] == 34)
	{
		str = ft_strjoin(str, "\"\"");
		return (str);
	}
	temp = ft_strdup("");
	while (data[*i] != 34 && data[*i])
	{
		temp = case_nodol_quote(data, i, temp);
		if (data[*i] == '$')
			temp = case_dol_quote(data, env, i, temp);
	}
	temp = add_char_around(temp, '"');
	str = ft_strjoin(str, temp);
	free (temp);
	return (str);
}

char	*case_nodol_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	j = *i;
	while (data[*i] != '$' && data[*i] != 34 && data[*i])
		(*i)++;
	if (*i != j)
	{		
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
		free(temp);
	}
	return (str);
}

char	*case_dol_quote(char *data, char **env, int *i, char *str)
{
	char	*temp;
	char	*temp2;
	int		j;

	(*i)++;
	j = *i;
	if (!ft_isalnum(data[*i]))
	{
		str = ft_strjoin(str, "$");
		return (str);
	}
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
	return (str);
}

char	*case_single_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	(*i)++;
	if (data[*i] == 39)
	{
		str = ft_strjoin(str, "\'\'");
		return (str);
	}
	j = *i;
	while (data[*i] != 39 && data[*i])
		(*i)++;
	temp = ft_substr(data, j, *i - j);
	temp = add_char_around(temp, '\'');
	str = ft_strjoin(str, temp);
	free(temp);
	return (str);
}
