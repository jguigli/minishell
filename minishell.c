#include "./includes/minishell.h"

int status;

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	t_main	*main;

	manage_signal();
	main = init_main();
	if (!search_in_env_var("PATH", env))
		main->env = manage_env_i();
	else
		main->env = get_copy(env); //A FREE A LA FIN
	get_prompt(main);
	return (0);
}