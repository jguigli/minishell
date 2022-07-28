/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:58:24 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:58:29 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*loop_expansion(t_datas *list, char **env, int *cut, char *str)
{
	int		i;

	i = 0;
	while (list->data[i])
	{
		str = case_nodol_noquote(list->data, &i, str);
		if (list->data[i] == '$' && list->data[i + 1] == '?')
			str = case_g_status(&i, str);
		else if (list->data[i] == '$')
		{
			str = case_dol_noquote(list->data, env, &i, str);
			if (str[0] != '\0')
				*cut = 1;
		}
		else if (list->data[i] == 34)
			str = manage_dquote(list->data, env, &i, str);
		else if (list->data[i] == 39)
			str = case_single_quote(list->data, &i, str);
		if (list->data[i] != '\0')
			i++;
	}
	return (str);
}

static int	manage_expansion(t_datas *list, char **env, int *cut)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	str = loop_expansion(list, env, cut, str);
	if (list->type == 21 && str[0] == '\0')
	{
		error_msg_redir(list->data, AMBIG);
		free(str);
		return (1);
	}
	free(list->data);
	list->data = str;
	return (0);
}

static t_datas	*skip_heredoc(t_datas *list, int *stopit)
{
	if (list->type == 33 && list->next->next)
		list = list->next->next;
	if (list->type == 39)
	{
		if (list->next)
			list = list->next;
		else
			*stopit = 1;
	}
	return (list);
}

static int	main_exp(t_dblist *gr_list, t_datas *list, char **env, int *cut)
{
	*cut = 0;
	(void)gr_list;
	if (manage_expansion(list, env, cut))
		return (1);
	if (list->type == 21 && list->data[0] == '"' && list->data[1] == '"'
		&& list->data[2] == '\0')
	{
		error_msg_redir("", FILE);
		return (1);
	}
	return (0);
}

int	shell_parameter_expansion(t_dblist *gr_list, char **env)
{
	t_datas	*list;
	int		cut;

	list = gr_list->first;
	while (list)
	{
		cut = 0;
		list = skip_heredoc(list, &cut);
		if (cut)
			break ;
		else
		{
			if (main_exp(gr_list, list, env, &cut))
				return (1);
			if (cut && list->type != 21)
				list = word_splitting(gr_list, list);
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
	quote_removal(gr_list);
	return (0);
}
