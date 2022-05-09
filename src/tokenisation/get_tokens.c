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

t_dblist	*get_grps_tok(t_dblist *l, t_dblist *gr_list)
{
	t_dblist	*list;
	int	pos;

	list = l;
	pos = 0;
	while (list->first && list->first->next)
	{
		if (list->first->type == list->first->next->type)
		{
			list->first->data = ft_strjoin(list->first->data, " ");
			list->first->data = ft_strjoin(list->first->data, list->first->next->data);
			create_token_list(gr_list, list->first->data, pos, list->first->type);
			list->first = list->first->next->next;
			pos++;
		}
		else
		{
			create_token_list(gr_list, list->first->data, pos, list->first->type);
			list->first = list->first->next;
			pos++;
		}
	}
	if (list)
		create_token_list(gr_list, list->first->data, pos, list->first->type);
	return (gr_list);
}

t_dblist	*get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int token_typess;
	unsigned int i;
	unsigned int j;
	t_dblist	*list;
	t_dblist	*gr_list;
	int pos;

	i = 0;
	pos = 0;
	j = 0;
	list = init_linked_list(); // PRB RESOLU : j'ai renvoyé un pointeur sur t_dblist dans la fonction 	 au lieu de le prendre en argument (avant -> init_linked_list(list))
	gr_list = init_linked_list();
	char *str;
	char *temp;
	while (entry[i]) // METTRE A JOUR LES CHR RULES (voir commentaires dans cette fonction)
	{
		token_type = g_get_tok_type[g_get_chr_class[entry[i]]];
		while (g_token_chr_rules[token_type][g_get_chr_class[entry[i]]])
		{
			i++;
		}
		str = malloc(sizeof(char) * (i - j) + 1);
		str = ft_substr(entry, j, i - j);
		pos++;
		create_token_list(list, str, pos, token_type);
		i++;
		j = i;
	}
	gr_list = get_grps_tok(list, gr_list);
	while (gr_list->first)
	{
		printf("%s\n", gr_list->first->data);
		gr_list->first = gr_list->first->next;
	}
	return (gr_list);
}