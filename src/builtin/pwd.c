#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*str;

	g.status = 0;
	str = getcwd(NULL, 0);
	if (!str)
		return (-1);
	printf("%s\n", str);
	return (0);
}
