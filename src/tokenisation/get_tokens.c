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
	t_dblist	*copy;

	copy = l;
	printf("a partir token %d\n", copy->number);
	//printf("la\n");
	if (!copy->number)
	{
		element = malloc(sizeof(t_datas));
		if (!element)
			exit(EXIT_FAILURE);
		copy->first = element;
		element->data = s;
		element->next = NULL;
		element->previous = NULL;
		element->pos = pos;
		element->type = t;
		copy->last = element;
		copy->number++;
	}
	else
	{
		current = copy->first;
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
		copy->last = element;
		copy->number++;
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
	//printf("number = %d\n", list->number)
	char *str;
	while (entry[i])
	{
		j = i;
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]]; // TOKENIZER : indique si le caractere 
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]]) // LEXER : verifie si le token [i] est bon a etre enregistré
		{

			i++;
			if (!g_token_chr_rules[token_type][g_get_chr_class[entry[i + 1]]]) // si l'element a i + 1 
			pos++;
		}
		str = ft_substr(entry, j, i - j);
		//printf("%s\n", str);
		create_token_list(list, str, pos, token_type);
		i++;
	}
	return (list);
}