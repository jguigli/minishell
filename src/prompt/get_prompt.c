/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:01:57 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/03 17:05:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_prompt_env(void)
{
	char	*name;
	char	*pwd;
	char	*prompt;
	char	*temp;

	temp = NULL;
	temp = ft_strjoin(temp, "\x1b[32m");
	name = ft_strdup("minishell");
	if (!name)
		return (free(temp), NULL);
	temp = ft_strjoin(temp, name);
	free(name);
	name = ft_strjoin(temp, "\x1b[0m:");
	temp = NULL;
	temp = ft_strjoin(temp, "\x1b[34m");
	pwd = getcwd(NULL, 0);
	temp = ft_strjoin(temp, pwd);
	if (pwd)
		free(pwd);
	pwd = ft_strjoin(temp, "\x1b[0m$ ");
	prompt = ft_strjoin(name, pwd);
	free(pwd);
	return (prompt);
}

static void	manage_prompt(char *entry, t_main *main)
{
	int	get_p;

	get_p = 1;
	entry = readline(main->my_prompt);
	main->sigintos = 0;
	if (entry == NULL)
	{
		write(1, "exit\n", 6);
		closing(main);
		close(1);
		ft_free(main);
		exit(g_status);
	}
	add_history(entry);
	main->start = parse_args(entry, main);
	if (!main->start)
		get_p = 0;
	if (get_p == 1)
	{
		exec_launcher(main);
		free_flist(main->start);
	}
}

void	get_prompt(t_main *main)
{
	char	*entry;
	int		int_mode;

	int_mode = 1;
	entry = NULL;
	while (int_mode)
	{
		main->my_prompt = get_prompt_env();
		int_mode = isatty(STDIN_FILENO);
		main->start = NULL;
		main->exec_c = NULL;
		main->exec_s = NULL;
		if (int_mode == 1)
			manage_prompt(entry, main);
		free (main->my_prompt);
	}
}
