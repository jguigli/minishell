#include "../../includes/minishell.h"

void	ft_env(char **arg, char **env)
{
	int	i;

	i = 0;
	status = 0;
	printf("LAAAAAAAAAAAAAAAA dans ft env\n");
	if (!arg[1])
	{
		if (!env)
			return ;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		printf("env: too much arguments\n");
		status = 2;
	}
}
