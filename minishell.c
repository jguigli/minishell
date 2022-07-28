/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:44:58 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/09 13:50:03 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	g_status;

void	manage_env(t_main *main, char *envcheck, char **env)
{
	if (!envcheck)
	{
		main->env = manage_env_i();
		main->export = manage_env_i();
	}
	else
	{
		main->env = get_copy(env);
		main->export = get_copy(env);
		free(envcheck);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_main	*main;
	char	*envcheck;

	(void)argv;
	if (argc != 1)
	{
		printf("Error arguments\n");
		return (-1);
	}
	manage_signal();
	main = init_main();
	envcheck = search_in_env_var("PATH", env);
	manage_env(main, envcheck, env);
	get_prompt(main);
	return (0);
}
