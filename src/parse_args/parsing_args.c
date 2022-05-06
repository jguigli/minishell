#include "../../includes/minishell.h"

void	parse_args(char	*entry)
{
	if (check_quote(entry) == 1)
	{
		get_tokens(entry);
	}
}