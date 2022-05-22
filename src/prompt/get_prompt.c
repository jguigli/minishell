#include "../../includes/minishell.h"

char	*get_env_pwd(char **env)
{
	int	i;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PWD", env[i], 3))
			break ;
		i++;
	}
	str = ft_strdup(&env[i][4]);
	return (str);
}

char	*get_env_name(char **env)
{
	int	i;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("USER", env[i], 4))
			break ;
		i++;
	}
	str = ft_strdup(&env[i][5]);
	return (str);
}

char	*get_prompt_env(char **env)
{
	char	*name;
	char	*pwd;
	char	*prompt;

	name = get_env_name(env);
	pwd = get_env_pwd(env);
	name = ft_strjoin(name, ":");
	pwd = ft_strjoin(pwd, "$ ");
	prompt = ft_strjoin(name, pwd);
	return (prompt);
}

void	get_prompt(char **env) // (void) => (char **env) anciennement
{
	char	*entry;
	int		int_mode;
	char	*my_prompt;

	my_prompt = get_prompt_env(env);
	while(int_mode) // shouldrun est une variable de la struct globale qui permettra d'arreter la boucle si signal reçu ou autres erreurs
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			entry = readline(my_prompt);
			if (entry == NULL) // correspond a ctrl -d -> envoi EOF sur la stdin, readline renvoi NULL, quand il lis le EOF
			{
				write(1, "exit", 5);
				exit(0); // free le tout
			}
			// RAJOUTER CONDITION SI CA FOIRE
	    	add_history(entry); //add it to the history
			parse_args(entry, env);
        }
	}
}