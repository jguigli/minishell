#include "../../includes/minishell.h"

void	parse_args(char	*entry)
{
	if (check_quote(entry) == 1)
	{
		get_tokens(entry);
	}
	// implémenter la fonction pour gérer les incohérences de contexte (exemple "><" -> existe pas, mais le lexer le copiera)
	// while (list) -> on check les éléments
}