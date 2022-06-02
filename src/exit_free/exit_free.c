#include "../../includes/minishell.h"

void	to_exit(t_datas *list)
{
	if (!list)
	{
		write(1, "Error \n", 8);
		return ;
	}
}