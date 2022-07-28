/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:59:55 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:59:56 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*remove_double_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	(*i)++;
	if (data[*i] == '\0')
	{
		str = ft_strjoin(str, "\"");
		return (str);
	}
	j = *i;
	while (data[*i] != 34 && data[*i])
		(*i)++;
	if (*i != j)
	{
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
		free(temp);
	}
	return (str);
}

static char	*remove_single_quote(char *data, int *i, char *str)
{
	char	*temp;
	int		j;

	(*i)++;
	j = *i;
	while (data[*i] != 39 && data[*i])
		(*i)++;
	if (*i != j)
	{
		temp = ft_substr(data, j, *i - j);
		str = ft_strjoin(str, temp);
		free(temp);
	}
	return (str);
}

static void	remove_quote(t_datas *list)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	i = 0;
	str = ft_strdup("");
	temp = NULL;
	while (list->data[i])
	{
		j = i;
		while (list->data[i] != 34 && list->data[i] != 39 && list->data[i])
			i++;
		temp = ft_substr(list->data, j, i - j);
		str = ft_strjoin(str, temp);
		free(temp);
		if (list->data[i] == 34)
			str = remove_double_quote(list->data, &i, str);
		else if (list->data[i] == 39)
			str = remove_single_quote(list->data, &i, str);
		if (list->data[i] != '\0')
			i++;
	}
	free(list->data);
	list->data = str;
}

void	quote_removal(t_dblist *gr_list)
{
	t_datas	*list;

	list = gr_list->first;
	while (list)
	{
		if (list->type == 33 && list->next->next)
			list = list->next->next;
		if (list->type == 39)
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		else
			remove_quote(list);
		if (list->next)
			list = list->next;
		else
			break ;
	}
}
