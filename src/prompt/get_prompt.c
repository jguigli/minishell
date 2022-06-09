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

char	*get_prompt_env(char **env) // RAJOUTER DES PROTEC
{
	char	*name;
	char	*pwd;
	char	*prompt;
	char	*temp;

	temp = ft_strdup("");
	temp = ft_strjoin(temp, "\x1b[32m");
	name = search_in_env_var("USER", env);
	if (!name)
		return (free(temp), NULL);
	temp = ft_strjoin(temp, name);
	//free(name);
	name = ft_strjoin(temp, "\x1b[0m:");
	temp = ft_strdup("");
	temp = ft_strjoin(temp, "\x1b[34m");
	pwd = search_in_env_var("PWD", env);
	if (!pwd)
		return (free(name), free(temp), NULL);
	temp = ft_strjoin(temp, pwd);
	//free(pwd);
	pwd = ft_strjoin(temp, "\x1b[0m$ ");
	prompt = ft_strjoin(name, pwd);
	free(pwd);
	return (prompt);
}

void	get_prompt(char **env)
{
	char	*entry;
	int		int_mode;
	char	*my_prompt;
	t_flist	*gr_list;

	int_mode = 1;
	while (int_mode)
	{
		my_prompt = get_prompt_env(env);
		if (!my_prompt)
			my_prompt = "~$ ";
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			entry = readline(my_prompt);
			if (entry == NULL)
			{
				//printf("LOL");
				write(1, "exit", 5);
				exit(0);
			}
			//printf("entryyyyyyyyyy == %s\n", entry);
			add_history(entry);
			if (entry[0] && (entry[0] != ' ' && entry[0] != '\t'))
			{
			//	printf("heheheh\n");
				gr_list = parse_args(entry, env);
				exec_launcher(&gr_list, env);
			}
			else
				g.status = 0;
		}
	}
}
