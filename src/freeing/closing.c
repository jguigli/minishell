/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:30:36 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/22 19:38:41 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	closing(t_main *main)
{
	close_openfds(main);
	closing_bis(main);
}

void	closing_bis(t_main *main)
{
	if (main->my_oldfds[0] != -200 && main->my_oldfds[0] != -1)
	{
		close(main->my_oldfds[0]);
	}
	if (main->my_oldfds[1] != -200 && main->my_oldfds[1] != -1)
	{
		close(main->my_oldfds[1]);
	}
}

void	get_origin_fd(t_main *main)
{
	main->my_oldfds[1] = dup(STDIN_FILENO);
	main->my_oldfds[0] = dup(STDOUT_FILENO);
}

void	err_cmd_arg(t_main *main)
{
	closing(main);
	close(0);
	close(1);
	ft_free(main);
	exit(EXIT_FAILURE);
}
