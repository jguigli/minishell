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

	i = 1;
	pos = 0;
	/*  *********************************
	AMINA : COMMENTAIRES COMPREHENSION 
	La variable g_get_chr_class est un tableau regroupant des t_chr_class et prend en param le caractere et nous renvoie sa valeur dans la liste enum
	printf("GET CHR CLASS %u \n", g_get_chr_class['$']);
	Ici, g_get_chr_class['$'] renvoie la valeur 10 -> position de CHR_DOLLAR DANS LA LISTE ENUM t_chr_class
	********************************* */

	/*  *********************************
	AMINA : COMMENTAIRES COMPREHENSION 
	La variable g_get_tok_type est un tableau regroupant des t_tok_type et prend en param l'index du resultat de la variable get_chr_class et nous renvoie sa valeur dans la liste enum
	printf("GET TOK TYPE %u \n", g_get_tok_type[10]);
	Ici, g_get_tok_type[10] renvoie la valeur 10 -> position de CHR_WILDC DANS LA LISTE ENUM t_GET_TOK_TYPE et donc la position 9 dans la liste enum g_get_chr_class
	Cela permet de faire correspondre les deux listes et ainsi constituer le token
	********************************* */
	char *str;
	while (entry[i])
	{
		j = 0;
		// avec token_type, on recupere le type de token a partir du premier caractere
		//printf("%u\n", g_get_chr_class[entry[0]]);
		token_type = g_get_tok_type[g_get_chr_class[entry[0]]];
		//printf("%u\n", token_type);
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]])
		{

			//printf("%c", entry[i]);
			//printf("%d\n", g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]);
			i++;
			//fct qui permet de creer la cellule de la liste chaine
		}
		//str = malloc(sizeof(char) * i + 1);
		str = ft_substr(entry, j, i);
		printf("str %s\n", str);
		i++;
		j = i;
	}
	return (i);
}