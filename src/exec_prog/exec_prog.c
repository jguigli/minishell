/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:18:00 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:18:02 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	int		i;
	char	*builtin[8];

	i = 0;
	builtin[0] = "cd";
	builtin[1] = "echo";
	builtin[2] = "env";
	builtin[3] = "exit";
	builtin[4] = "export";
	builtin[5] = "pwd";
	builtin[6] = "unset";
	builtin[7] = 0;
	while (builtin[i])
	{
		if (!ft_strcmp(builtin[i], cmd))
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(char **arg, t_main *main)
{
	if (!strcmp(arg[0], "cd"))
		ft_cd(arg, main);
	else if (!strcmp(arg[0], "echo"))
		ft_echo(arg);
	else if (!strcmp(arg[0], "env"))
		ft_env(arg, main->env);
	else if (!strcmp(arg[0], "exit"))
		ft_exit(arg, main);
	else if (!strcmp(arg[0], "export"))
		ft_export(arg, main);
	else if (!strcmp(arg[0], "pwd"))
		ft_pwd(arg);
	else if (!strcmp(arg[0], "unset"))
		ft_unset(arg, main);
	return ;
}

char	**list_to_tab(t_dblist *list)
{
	char	**tab;
	int		size;
	int		i;
	t_datas	*current;

	i = 0;
	if (list->first == NULL)
		return (NULL);
	current = list->first;
	size = my_lstsize_dblist(list);
	if (current->data[0] == '\0' && current->next == NULL
		&& (current->type != TOKEN_DQUOTE && current->type != TOKEN_SQUOTE))
		return (NULL);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (current)
	{
		tab[i] = ft_strdup(current->data);
		current = current->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	exec_launcher(t_main *main)
{
	int	pipe;

	pipe = my_lstsize(main->start) - 1;
	if (pipe > 0)
		exec_complex_cmd(main);
	else if (pipe == 0)
	{
		if (exec_simple_cmd(main) == -10)
			return (0);
	}
	return (1);
}
