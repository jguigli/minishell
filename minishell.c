#include "./includes/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	char	**my_env;
	//ATTENTION PLUSIEURS MALLOC DANS GET_COPY. A FREE A LA FIN
	manage_signal();
	my_env = get_copy(env);
	get_prompt();
	return (0);
}