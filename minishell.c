#include "./includes/minishell.h"

t_glob g; // PAS SUR DE CA

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	manage_signal();
	init_global();
<<<<<<< HEAD
	// int i = 0;
	// while(env[i])
	// 	printf("env -i avec bash = %s\n", env[i++]);
	if (!search_in_env_var("PATH", env))
		g.env = manage_env_i();
	else
		g.env = get_copy(env); //A FREE A LA FIN
=======
	// if (!search_in_env_var("PATH", env))
	// {
	// 	printf("looooool\n");
	// 	return (-1); // MSG ERROR 
	// }
	g.env = get_copy(env); //ATTENTION PLUSIEURS MALLOC DANS GET_COPY. A FREE A LA FIN
	int i = 0;
	// while (g.env[i])
	// 	printf("env = %s\n", g.env[i++]);
>>>>>>> 2069653c072e08b3920e015c696e2d67ed0ed5ff
	get_prompt(g.env);
	return (0);
}