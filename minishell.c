#include "./includes/minishell.h"

t_glob g; // PAS SUR DE CA

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	char **envp;

	manage_signal();
	init_global();
	if (!search_in_env_var("PATH", env))
		envp = manage_env_i();
	else
		envp = get_copy(env); //A FREE A LA FIN
	get_prompt(envp);
	return (0);
}