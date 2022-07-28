/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:54 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:21:56 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	export_appreciate_symbol(char arg)
{
	if (arg == '-' || arg == '+' || arg == '*' || arg == '#' || arg == ':'
		|| arg == '$' || arg == '/' || arg == '\\' || arg == ':'
		|| arg == '=' || arg == '[' || arg == ']' || arg == '{'
		|| arg == '}' || arg == ',' || arg == '@' || arg == ' '
		|| arg == '|' || arg == '\'' || arg == '\"')
		return (1);
	return (0);
}

char	**dup_env_tab(char **env)
{
	int		i;
	char	**tab;

	i = 0;
	while (env[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static char	**tab_sorted_export(char **export)
{
	int		i;
	int		j;
	char	**tab;
	char	*temp;

	i = 0;
	tab = dup_env_tab(export);
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	free_char_tab(export);
	return (tab);
}

void	print_tab_export(char **tab, int *i, int *j, int *lim)
{
	printf("export ");
	while (tab[*i][*j])
	{
		printf("%c", tab[*i][*j]);
		if (tab[*i][*j] == '=' && *lim == 0)
		{
			printf("\"");
			*lim = 1;
		}
		(*j)++;
	}
	if (*lim == 1)
		printf("\"");
	printf("\n");
	(*i)++;
}

void	print_export(t_main *main)
{
	int		i;
	int		j;
	int		lim;

	i = 0;
	main->export = tab_sorted_export(main->export);
	while (main->export[i])
	{
		j = 0;
		lim = 0;
		print_tab_export(main->export, &i, &j, &lim);
	}
}
