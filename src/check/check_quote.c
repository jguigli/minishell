#include "../../includes/minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	simpleq;
	int	doubleq;

	i = 0;
	// Amina, j'ai initialisé simple q et doubleq sinonon avait des nbres astronomiques
	simpleq = 0;
	doubleq = 0;
	while (str[i])
	{
		if (str[i] == 34)
			doubleq++;
		if (str[i] == 39)
			simpleq++;
		i++;
	}
	if (!(doubleq % 2) && !(simpleq % 2))
		return (1);
	else
		return (0);
}