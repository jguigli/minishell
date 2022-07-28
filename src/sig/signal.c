/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:46:03 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 20:47:35 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sigint(int sig)
{
	(void)sig;
	g_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_sigquit(int sig)
{
	(void)sig;
	ft_putstr_fd("\b \b\b \b \b", 2);
	return ;
}

int	manage_signal(void)
{
	signal(SIGINT, &ft_sigint);
	signal(SIGQUIT, &ft_sigquit);
	return (0);
}

void	sig_quit_child(int sig)
{
	if (sig == 3)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g_status = 131;
	}
}

char	*ft_trunc(char *name)
{
	unsigned long	i;
	char			*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(name) - 2));
	while (i < ft_strlen(name) - 2)
	{
		ret[i] = name[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
