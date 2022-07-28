/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:48:43 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:48:45 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	count_quote(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (argv[i] == 39 || argv[i] == 34)
			count++;
		i++;
	}
	return (count);
}

char	*hd_removedquote(char *str)
{
	int		i;
	int		j;
	char	*rep;

	i = 0;
	j = 0;
	rep = ft_strdup("");
	while (str[i])
	{
		j = i;
		while (str[i] != 34 && str[i] != 39 && str[i])
			i++;
		if (i != j)
			rep = if_is_no_quoted(str, rep, i, j);
		if (str[i] == '\"')
			rep = if_is_dquoted(str, rep, &i, j);
		else if (str[i] == '\'')
			rep = if_is_squoted(str, rep, &i, j);
		if (str[i] != '\0')
			i++;
	}
	free (str);
	return (rep);
}

char	*hd_expansion(char *str, t_main *main)
{
	int		i;
	int		j;
	char	*rep;

	i = 0;
	j = 0;
	rep = ft_strdup("");
	while (str[i])
	{
		j = i;
		while (str[i] != '$' && str[i])
			i++;
		if (i != j)
			rep = if_is_no_dol(str, rep, i, j);
		if (str[i] == '$')
			rep = if_is_dol(str, rep, &i, main->env);
	}
	return (rep);
}
