#include "./includes/minishell.h"

t_glob g; // PAS SUR DE CA

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	manage_signal();
	init_global();
	// if (!search_in_env_var("PATH", env))
	// {
	// 	printf("looooool\n");
	// 	return (-1); // MSG ERROR 
	// }
	g.env = get_copy(env); //ATTENTION PLUSIEURS MALLOC DANS GET_COPY. A FREE A LA FIN
	int i = 0;
	// while (g.env[i])
	// 	printf("env = %s\n", g.env[i++]);
	get_prompt(g.env);
	return (0);
}