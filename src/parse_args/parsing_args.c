#include "../../includes/minishell.h"

void	parse_args(char	*entry)
{
	if (check_quote(entry) == 1 && ft_strlen(entry) > 0)
		get_tokens(entry);
	return ;
}