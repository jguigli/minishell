#include "./includes/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	char	**my_env;
	manage_signal();
	if (!*env)
		return (-1); // MSG ERROR
	my_env = get_copy(env); //ATTENTION PLUSIEURS MALLOC DANS GET_COPY. A FREE A LA FIN
	get_prompt(my_env);
	return (0);
}