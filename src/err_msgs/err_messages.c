#include "../../includes/minishell.h"

void	error_msgs(void)
{
	perror("Error ");
	exit(1);
}

int	syntax_err(char *error, char *data)
{
	// write(2, error, ft_strlen(error) + 1);
	// write(2, " ", 2);
	// write(2, data, ft_strlen(data));
	// write(2, data, ft_strlen(data));
	printf("minishell: %s %s\n", error, data);
	g.status = 2;
	return (0);
	// exit(1);
}

int	isdir_err(char *error, char *data)
{
	// write(2, error, ft_strlen(error) + 1);
	// write(2, " ", 2);
	// write(2, data, ft_strlen(data));
	// write(2, data, ft_strlen(data));
	printf("minishell: %s: %s\n", data, error);
	g.status = 2;
	return (0);
	// exit(1);
}

int	cmd_not_found(char *error)
{
	write(2, error, ft_strlen(error));
	exit(127);
}
