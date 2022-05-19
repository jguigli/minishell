#include "../../includes/minishell.h"

void	get_prompt(void) // (void) => (char **env) anciennement
{
	char	*entry;
	int		int_mode;
	char	*my_prompt;

	my_prompt = "~$ ";
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
			parse_args(entry);
        }
	}
}