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

int affiche(t_dblist *list)
{
	t_datas *current;
	int	i;
	static int count = 0;

	current = list->first;
	i = 0;
	printf("\nListe de tokens :\n");
	while (i < list->number)
	{
		printf("\tListe numéro %d :\n", i);
		printf("\t- Valeur token : %s\n", current->data);
		printf("\t- Position token : %d\n", current->pos);
		printf("\t- Type de token : %s\n", current->t_token);
		printf("\t- Numero du token : %d\n\n", current->type);
		current = current->next;
		i++;
	}
	count++;
	return(count);
}

void	create_token_list(t_dblist *l, char *s, int pos, unsigned int t)
{
	t_datas *element;
	t_datas *current;

	element = malloc(sizeof(t_datas));
	if (!element)
		exit(EXIT_FAILURE);
	if (!l->number)
	{
		l->first = element;
		element->data = s;
		element->t_token = NULL;
		element->pos = pos;
		element->type = t;
		element->next = NULL;
		element->previous = NULL;
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
		element->t_token = NULL;
		element->pos = pos;
		element->type = t;
		element->next = NULL;
		element->previous = current;
		l->last = element;
		l->number++;
	}
}

t_dblist	*get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int preced;
	unsigned int i;
	unsigned int j;
	t_dblist	*list;
	int pos;

	i = 0;
	pos = 0;
	preced = 0;
	list = init_linked_list(); // PRB RESOLU : j'ai renvoyé un pointeur sur t_dblist dans la fonction au lieu de le prendre en argument (avant -> init_linked_list(list))
	char *str;
	char *temp;
	while (entry[i]) // METTRE A JOUR LES CHR RULES (voir commentaires dans cette fonction)
	{
		j = i;
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]]; // TOKENIZER : indique si le caractere 
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]) // LEXER : verifie si le token [i] est bon a etre enregistré
		{
			//printf("%c\n", entry[i]);
			//printf("token type = %d\n", token_type);
			//printf("rules = %d\n", g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]);
			i++;
			// QUOTES CAS 1: est ce qu'on les gères ici avec le tokenizer ?
		if (i != j) // si i différent de j ca veut dire que gtoken chr rules à avancer dans la str, du coup on vient substr ce qu'il faut
		{
			if (token_type == preced && preced == TOKEN_WORD) // si le token précédent est un token word et que le token actuel est aussi un word alors on strjoin le tout
			{

				temp = ft_substr(entry, j, i - j);
				str = ft_strjoin(str, " ");
				str = ft_strjoin(str, temp);
				free(temp);
				//
				// QUOTES CAS 2 : check si la str a des quotes
				//si oui, fonction pour trim les quotes comme il faut
				//et si "$"", remplacer la variable $ par la bonne variable env
				//verifier si la var env existe, sinon renvoyer "\n" sur la stdout
				//
				if (g_get_tok_type[g_get_chr_class[entry[i + 2]]] != TOKEN_WORD) // problème avec le i + 2, car si il y a un espace à la place ca fonctionnera pas la condition (modif les chr rules)
				{
					create_token_list(list, str, pos, token_type);
					pos++;
				}
				preced = token_type;
			}
			else // la ou passe le premier token
			{
				str = ft_substr(entry, j, i - j);
				if (g_get_tok_type[g_get_chr_class[entry[i + 2]]] == TOKEN_WORD && token_type == TOKEN_WORD) //si c'est un token word et que le prochain est token word alors on créer pas une liste (la str sera str join dans le if au dessus)
					; // problème avec le i + 2 ligne au dessus, car si il y a un espace à la place ca fonctionnera pas la condition (modif les chr rules)
				else // création des autres tokens
				{
					create_token_list(list, str, pos, token_type);
					pos++;
				}
				preced = token_type;
			}
		}
			i++;
	}
	}
	affiche(list);
	return (list);
	// Amina test version 
}