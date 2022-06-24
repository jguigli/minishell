#include "./includes/minishell.h"

int status;

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	t_main	*main;
	char	*envcheck;

	main = init_main();
	manage_signal(main);
	if (!search_in_env_var("PATH", env))
	envcheck = search_in_env_var("PATH", env);
	if (!envcheck)
		main->env = manage_env_i();
	else
	{
		main->env = get_copy(env); //A FREE A LA FIN
		free(envcheck);
	}
	get_prompt(main);
	return (0);
}