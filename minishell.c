#include "./includes/minishell.h"

t_glob g; // PAS SUR DE CA

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	manage_signal();
	init_global();
	if (!search_in_env_var("PATH", env))
		g.env = manage_env_i();
	else
		g.env = get_copy(env); //A FREE A LA FIN
	get_prompt();
	return (0);
}