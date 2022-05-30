#include "../../includes/minishell.h"

void    ft_echo(char **arg)
{
	int	i;

	i = 1;
	if (!arg[1])
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	//checker si -n est present
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		i++;
		if (arg[i])
			ft_putchar_fd(' ', 1);
	}
	if (n)
		ft_putchar_fd('\n');
	return (0);
}