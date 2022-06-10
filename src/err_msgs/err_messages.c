#include "../../includes/minishell.h"

void	error_msgs(int error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	g.status = 1;
	return ;
}

void	syntax_err(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g.status = 2;
}

void	isdir_err(char *error, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g.status = 2;
}

void	cmd_not_found(char *error, char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g.status = 127;
}
