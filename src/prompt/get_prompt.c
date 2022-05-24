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

char	*get_prompt_env(char **env) // RAJOUTER DES PROTEC
{
	char	*name;
	char	*pwd;
	char	*prompt;
	char	*temp;

	temp = ft_strdup("");
	temp = ft_strjoin(temp, "\x1b[32m");
	name = get_env_name(env);
	temp = ft_strjoin(temp, name);
	name = ft_strjoin(temp, "\x1b[0m:");
	temp = ft_strdup("");
	temp = ft_strjoin(temp, "\x1b[34m");
	pwd = get_env_pwd(env);
	temp = ft_strjoin(temp, pwd);
	pwd = ft_strjoin(temp, "\x1b[0m$ ");
	prompt = ft_strjoin(name, pwd);
	free(pwd);
	return (prompt);
}

void	get_prompt(char **env) // (void) => (char **env) anciennement
{
	char	*entry;
	int		int_mode;
	char	*my_prompt;

	my_prompt = get_prompt_env(env);
	while(int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			entry = readline(my_prompt);
			if (entry == NULL)
			{
				write(1, "exit", 5);
				exit(0);
			}
			// RAJOUTER CONDITION SI CA FOIRE
	    	add_history(entry);
			parse_args(entry, env);
        }
	}
}