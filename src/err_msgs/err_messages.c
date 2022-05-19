#include "../../minishell.h"

void	error_msgs(void)
{
	perror("Error ");
	exit(1);
}

int	pers_err_msges(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

int	cmd_not_found(char *error)
{
	write(2, error, ft_strlen(error));
	exit(127);
}
