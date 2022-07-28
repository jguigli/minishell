/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:23:40 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:23:42 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_option_pwd(char *arg)
{
	if (arg[0] == '-')
	{
		if (arg[1] == '-' && !arg[2])
			return (1);
		else
		{
			syntax_err_option(PWD, arg, OPTION);
			return (0);
		}
	}
	return (1);
}

void	ft_pwd(char **arg)
{
	char	*str;

	g_status = 0;
	if (arg[1])
	{
		if (!check_option_pwd(arg[1]))
			return ;
	}
	str = getcwd(NULL, 0);
	if (!str)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 2);
		return ;
	}
	printf("%s\n", str);
	free (str);
}
