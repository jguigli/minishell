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

void	create_token_list(t_dblist *l, char *s, int pos, unsigned int t)
{
	t_datas *element;
	t_datas *current;

	if (!l->number)
	{
		element = malloc(sizeof(t_datas));
		if (!element)
			exit(EXIT_FAILURE);
		l->first = element;
		element->data = s;
		element->next = NULL;
		element->previous = NULL;
		element->pos = pos;
		element->type = t;
		l->last = element;
		l->number++;
	}
	else
	{
		current = l->first;
		while (current->next)
		{
			current = current->next;
		}
		current->next = element;
		element->data = s;
		element->next = NULL;
		element->previous = current;
		element->pos = pos;
		element->type = t;
		l->last = element;
		l->number++;
	}
}

t_dblist	*get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int i;
	unsigned int j;
	t_dblist	*list;
	int pos;

	i = 0;
	pos = 0;
	init_linked_list(list);
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
		j = i;
		// avec token_type, on recupere le type de token a partir du premier caractere
		//printf("%u\n", g_get_chr_class[entry[0]]);
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]]; // TOKENIZER : indique si le caractere est un WORD, ESP, PIPE, etc..
		//printf("%u\n", token_type);
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]) // LEXER : verifie si le token [i] est bon a etre enregistré
		{

			//printf("%c", entry[i]);
			//printf("%d\n", g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]);
			// COMMENT RECUPERER LE TOKEN EN STR POUR LE TYPE DE TOKEN A METTRE DANS LA FONCTION
			i++;
			if (!g_token_chr_rules[token_type][g_get_chr_class[entry[i + 1]]]) // si l'element a i + 1 est pas un token valide on augmente la position pour le prochain token valide quand on rerentrera dans la boucle while
				pos++; 
		}
		str = ft_substr(entry, j, i - j);
		create_token_list(list, str, pos, token_type);
		printf("%s\n", str);
		i++;
	}
	return (list);
}