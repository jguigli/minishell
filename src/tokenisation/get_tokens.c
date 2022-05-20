#include "../../includes/minishell.h"
#include "../../libft/libft.h"

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
		printf("\t- Numero du token : %d\n", current->type);
		printf("\t- Level : %d\n", current->level);
		printf("\t- SPACE : %d\n\n", current->space);
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
	char types[1024][1024] = {"TOKEN_ERROR","TOKEN_SP","TOKEN_BANG","TOKEN_AND","TOKEN_SEMI","TOKEN_WORD","TOKEN_RRED","TOKEN_LRED","TOKEN_ESCAPE","TOKEN_DIGIT","TOKEN_DOL","TOKEN_PIPE","TOKEN_SQUOTE","TOKEN_DQUOTE","TOKEN_BQUOTE","TOKEN_LPAREN","TOKEN_RPAREN","TOKEN_HYPHEN","TOKEN_LBRACE","TOKEN_RBRACE","TOKEN_WILDC","TOKEN_FILE", "TOKEN_EQ", "TOKEN_EOF", "TOKEN_MAX"};
	/* POur les niveaux :
		- Niveau 4 = pipes, &, $
		- Niveau 3 = redirection ; > >> <
		- Niveau 2 = mots
		- Niveau 1 = doubleQ / SingleQ / brackets / parenthesis
		- Niveau 0 = file
	*/
	int levels[1024] = {0, 1, 0, 4, 4, 2, 2, 3, 2 ,2, 4, 4, 1, 1, 1, 1, 1, 2, 1, 1, 2, 0, 10};
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
		element->t_token = types[t];
		element->level = levels[t];
		element->next = NULL;
		element->space = l->infos->sp;
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
		element->t_token = types[t];
		element->level = levels[t];
		element->pos = pos;
		element->type = t;
		element->space = l->infos->sp;
		element->next = NULL;
		element->previous = current;
		l->last = element;
		l->number++;
	}
}

// t_dblist	*get_grps_tok(t_dblist *l, t_dblist *gr_list)
// {
// 	t_dblist	*list;
// 	int	pos;

// 	list = l;
// 	pos = 0;
// 	while (list->first && list->first->next)
// 	{
// 		if (list->first->type == list->first->next->type 
// 			|| ( list->first->type == 5 && list->first->next->type == 13) 
// 				|| ( list->first->type == 5 && list->first->next->type == 12))
// 		{
// 			while (list->first->type == list->first->next->type 
// 				|| ( list->first->type == 5 && list->first->next->type == 13) 
// 					|| ( list->first->type == 5 && list->first->next->type == 12))
// 			{
// 				if (list->first->space == 1)
// 					list->first->data = ft_strjoin(list->first->data, " ");
// 				list->first->data = ft_strjoin(list->first->data, list->first->next->data);
// 				list->first->space = list->first->next->space;
// 				if (list->first->next->next)
// 					list->first->next = list->first->next->next;
// 				else
// 				{
// 					pos++;
// 					create_token_list(gr_list, list->first->data, pos, list->first->type);
// 					return (gr_list);
// 				}
// 			}
// 			pos++;
// 			create_token_list(gr_list, list->first->data, pos, list->first->type);
// 			list->first = list->first->next;
// 		}
// 		else
// 		{
// 			if (list->first->type == 6)
// 			{
// 				pos++;
// 				create_token_list(gr_list, list->first->data, pos, list->first->type);
// 				list->first = list->first->next;
// 				list->first->type = 21;
// 			}
// 			pos++;
// 			create_token_list(gr_list, list->first->data, pos, list->first->type);
// 			if (list->first->next && list->first->next->next)
// 				list->first = list->first->next;
// 			else if (list->first->next && !list->first->next->next)
// 			{
// 				list->first = list->first->next;
// 				pos++;
// 				create_token_list(gr_list, list->first->data, pos, list->first->type);
// 				return (gr_list);
// 			}
// 			else
// 				return (gr_list) ;
// 		}
// 	}
// 	if (list->first && !list->first->next)
// 	{
// 		pos++;
// 		create_token_list(gr_list, list->first->data, pos, list->first->type);
// 		return (gr_list);
// 	}
// 	return (gr_list);
// }

int	check_dquotes_dol(t_datas *list)
{
	int	i;
	int	dq;
	int	dol;

	i = 0;
	dq = 0;
	dol = 0;
	while (list->data[i])
	{
		if (list->data[i] == 34)
			dq++;
		if (list->data[i] == '$')
			dol++;
		i++;
	}
	if (dq % 2 == 0 && dol == 1)
		return (-1); // double quote pair et dol
	else if (dq % 2 == 0 && dol == 0)
		return (-2); // double quote et pas de dol
	else if (dq % 2 == 0 && dol > 1)
		return (dol);
	else if (!(dq % 2))
		pers_err_msges(ARG);
}

int	check_squotes_dol(t_datas *list)
{
	int	i;
	int	sq;
	int	dol;

	i = 0;
	sq = 0;
	dol = 0;
	while (list->data[i])
	{
		if (list->data[i] == 39)
			sq++;
		if (list->data[i] == '$')
			dol++;
		i++;
	}
	if (sq % 2 == 0 && dol == 1)
		return (-1); // double quote pair et dol
	else if (sq % 2 == 0 && dol == 0)
		return (-2); // double quote et pas de dol
	else if (sq % 2 == 0 && dol > 1)
		return (dol);
	else if (!(sq % 2))
		pers_err_msges(ARG);
}

int	check_spec_char(t_datas *token, t_dblist *list)
{
	int	i;

	i = 0;
	while (token->data[i])
	{
		if (list->infos->get_chr_c[token->data[i]] != CHR_WORD)
			pers_err_msges(ARG);
		i ++;
	}
	return (0);
}

t_dblist *p_tok(t_dblist *list)
{
	t_dblist	*p_list;

	p_list = list;
	while(p_list->first)
	{
		p_list->first->length = ft_strlen(p_list->first->data);
		if	(p_list->first->type == 13)
		{
			if	(check_dquotes_dol(p_list->first) == -1)
			{
				list->first->dq = 1;
				list->first->dol = 1;
			}
			else if (check_dquotes_dol(p_list->first) == -2)
			{

				list->first->dq = 1;
				list->first->dol = 0;
			}
			else if (check_dquotes_dol(p_list->first) > 1)
			{

				list->first->dq = 1;
				list->first->dol = check_dquotes_dol(p_list->first);
			}
			else
				pers_err_msges(ARG);
			
		}
		else if	(p_list->first->type == 12)
		{
			if	(check_squotes_dol(p_list->first) == -1)
			{
				list->first->dq = 1;
				list->first->dol = 1;
			}
			else if (check_squotes_dol(p_list->first) == -2)
			{

				list->first->dq = 1;
				list->first->dol = 0;
			}
			else if (check_squotes_dol(p_list->first) > 1)
			{

				list->first->dq = 1;
				list->first->dol = check_squotes_dol(p_list->first);
			}
			else
				pers_err_msges(ARG);
		}
		else if	(p_list->first->type == 5)
			check_spec_char(p_list->first, p_list);
		else if (p_list->first->type == 11)
		{
			if	(p_list->first->length != 1)
				pers_err_msges(ARG);
		}
		else if (p_list->first->type == 6 || p_list->first->type == 7)
		{
			if (p_list->first->length == 1)
				p_list->first->redir = 1;
			else if (p_list->first->length == 2)
			{
				if (p_list->first->data[1] != p_list->first->data[0])
					pers_err_msges(ARG);
				p_list->first->redir = 2;
			}
			else
				pers_err_msges(ARG);
		}
		p_list->first = p_list->first->next;
	}
}

t_dblist	*get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int token_typess;
	unsigned int i;
	unsigned int j;
	int			is_quoted;
	t_dblist	*list;
	t_dblist	*p_list;
	int pos;

	i = 0;
	pos = 0;
	j = 0;
	list = init_linked_list();
	p_list = init_linked_list();
	char *str;

	while (entry[i])
	{
		token_type = list->infos->get_tok_type[list->infos->get_chr_c[entry[i]]];
		while (list->infos->get_chr_rules[token_type][list->infos->get_chr_c[entry[i]]] && is_quoted == 1)
		{
			if (entry[i] == '\"')
			{
				is_quoted = 1;
				i++;
				while(is_quoted == 1)
				{
					if (entry[i] == '\"' || list->infos->get_chr_c[entry[i]] == 22)
					{
						is_quoted = 0;
						break ;
					}
					i++;
				}
			}
			if (entry[i] == '\'')
			{
				is_quoted = 1;
				i++;
				while(is_quoted == 1)
				{
					if (entry[i] == '\'' || list->infos->get_chr_c[entry[i]] == 22)
					{
						is_quoted = 0;
						break ;
					}
					i++;
				}
			}
			if	(list->infos->get_chr_c[entry[i]] == 22)
				break ;
			i++;
		}
		if (token_type != 1) // MODIF
		{
			if (entry[i] == '\t' || entry[i] == ' ')
				list->infos->sp = 1;
			else 
				list->infos->sp = 2;
			
			str = ft_substr(entry, j, (i - j));
			pos++;
			create_token_list(list, str, pos, token_type);
		}
		if (is_quoted == 1)
			i++;
		else
			is_quoted = 1;
		j = i;
	}
	// gr_list = get_grps_tok(list, gr_list);
	// affiche(gr_list);
	// return (gr_list);
	affiche(list);
	p_tok(list);
	return (list);
}