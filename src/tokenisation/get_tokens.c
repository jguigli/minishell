#include "../../includes/minishell.h"

int	iswhitespace(char c)
{
	if	(c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_doublequote(char c)
{
	if	(c == '"')
		return (1);
	return (0);
}

int	is_simplequote(char c)
{
	if	(c == 39)
		return (1);
	return (0);
}

int	get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int i;
	unsigned int j;
	int pos;

	i = 0;
	pos = 0;
	while (entry[i])
	{
		j = i;
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]];
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]])
		{
			printf("%c", entry[i]);
			i++;
			//fct qui permet de creer la cellule de la liste chaine
		}
		printf("\n");
		i++;
	}
	return (i);
}