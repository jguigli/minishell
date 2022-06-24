/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:01:57 by ael-khat          #+#    #+#             */
/*   Updated: 2022/06/03 19:02:02 by ael-khat         ###   ########.fr       */
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
	if (!pwd)
		return (free(name), free(temp), NULL);
	temp = ft_strjoin(temp, pwd);
	free(pwd);
	pwd = ft_strjoin(temp, "\x1b[0m$ ");
	prompt = ft_strjoin(name, pwd);
	free(pwd);
	return (prompt);
}

void	get_prompt(t_main *main)
{
	char	*entry;
	int		int_mode;

	int_mode = 1;
	while (int_mode)
	{
		main->my_prompt = get_prompt_env();
		int_mode = isatty(STDIN_FILENO);
		main->start = NULL;
		if (int_mode == 1)
		{
			entry = readline(main->my_prompt);
			if (entry == NULL)
			{
				write(1, "exit\n", 6);
				ft_free(main);
				exit(status);
			}
			add_history(entry);
			//printf("entryyyyyy %s\n", entry);
			main->start = parse_args(entry, main->env);
			//main->start = gr_list;
			if (main->start)
			{
				//affiche(main->start->process);
				exec_launcher(main);
				free_flist(main->start);
			}
			free (main->my_prompt);
		}
	}
}