#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	*str;

	g.status = 0;
	str = getcwd(NULL, 0);
	if (!str)
		return ;
	printf("%s\n", str);
}
