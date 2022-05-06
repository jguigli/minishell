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
  	//t_datas *current2;
	int	i;
	//int j;
	static int count = 0;

	current = list->first;
	//current2 = list->last;
	i = 0;
	//j = 0;
	printf("\nListe de tokens :\n");
	while (i < list->number)
	{
		printf("\tListe numéro %d :\n", i);
		printf("\t- Valeur token : %s\n", current->data);
		printf("\t- Position token : %d\n", current->pos);
		printf("\t- Type de token : %s\n", current->t_token);
		printf("\t- Numero du token : %d\n\n", current->type);
		//current2 = current2->next;
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

	if (!l->number)
	{
		element = malloc(sizeof(t_datas));
		if (!element)
			exit(EXIT_FAILURE);
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
		element = malloc(sizeof(t_datas));
		if (!element)
			exit(EXIT_FAILURE);
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
	while (entry[i]) // METTRE A JOUR LES CHR RULES
	{
		j = i;
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]]; // TOKENIZER : indique si le caractere 
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]) // LEXER : verifie si le token [i] est bon a etre enregistré
		{
			//printf("%c\n", entry[i]);
			//printf("token type = %d\n", token_type);
			//printf("rules = %d\n", g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]);
			i++;
			if (!g_token_chr_rules[token_type][g_get_chr_class[entry[i + 1]]]) // si l'element a i + 1 
				pos++;
		}
		if (i != j)
		{
			if (token_type == preced)
			{
				temp = ft_substr(entry, j, i - j);
				str = ft_strjoin(str, " ");
				str = ft_strjoin(str, temp);
				free(temp);
				//check si la str a des quotes
				//si oui, fonction pour trim les quotes comme il faut
				//et si "$"", remplacer la variable $ par la bonne variable env
				//verifier si la var env existe, sinon renvoyer "\n" sur la stdout
				if (g_get_tok_type[g_get_chr_class[entry[i + 2]]] != TOKEN_WORD) // A MODIF : surement des cas ou ça ne passe pas (genre les "", ou les '')
				{
					create_token_list(list, str, pos, token_type);
				}
				preced = token_type;
			}
			else
			{
				str = ft_substr(entry, j, i - j);
				if (g_get_tok_type[g_get_chr_class[entry[i + 1]]] != token_type) // A MODIF : surement des cas où ca ne passe (exemple : salut || || amis, les tokens "||" ne sont plus pris en compte)
				{
					create_token_list(list, str, pos, token_type);
				}
				preced = token_type;
			}
			i++;
		}
	}
	affiche(list);
	return (list);
}