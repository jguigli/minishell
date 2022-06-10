#include "./includes/minishell.h"

t_glob g; // PAS SUR DE CA

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	manage_signal();
	init_global();
	// int i = 0;
	// while(env[i])
	// 	printf("env -i avec bash = %s\n", env[i++]);
	if (!search_in_env_var("PATH", env))
		g.env = manage_env_i();
	else
		g.env = get_copy(env); //A FREE A LA FIN
	get_prompt(g.env);
	return (0);
}