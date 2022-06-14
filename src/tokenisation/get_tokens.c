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
	while (current)
	{
		printf("\tListe numéro %d :\n", i);
		printf("\t- Valeur token : %s\n", current->data);
		printf("\t- Position token : %d\n", current->pos);
		printf("\t- Type de token : %s\n", current->t_token);
		printf("\t- Numero du token : %d\n", current->type);
		printf("\t- Level : %d\n", current->level);
		printf("\t- SPACE : %d\n", current->space);
		printf("\t- SIIIZE: %zu\n\n", ft_strlen(current->data));
		current = current->next;
		i++;
	}
	count++;
	return(count);
}

void	create_grtoken(t_dblist *l, char *data, char *tokt, int type)
{
	t_datas *element;
	t_datas *current;

	element = malloc(sizeof(t_datas));
	if (!element)
		exit(EXIT_FAILURE);
	if (!l->number)
	{
		l->first = element;
		element->data = data;
		element->t_token = tokt;
		element->type = type;
		element->pos = 0;
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
		element->data = data;
		element->t_token = tokt;
		element->pos = 0;
		element->type = type;
		element->next = NULL;
		element->previous = current;
		l->last = element;
		l->number++;
	}
}

void	create_token_list(t_dblist *l, char *s, int pos, unsigned int t)
{
	t_datas *element;
	t_datas *current;
	char types[1024][1024] = {"TOKEN_ERROR","TOKEN_SP","TOKEN_BANG","TOKEN_AND","TOKEN_SEMI","TOKEN_WORD","TOKEN_RRED","TOKEN_LRED","TOKEN_ESCAPE","TOKEN_DIGIT","TOKEN_DOL","TOKEN_PIPE","TOKEN_SQUOTE","TOKEN_DQUOTE","TOKEN_BQUOTE","TOKEN_LPAREN","TOKEN_RPAREN","TOKEN_HYPHEN","TOKEN_LBRACE","TOKEN_RBRACE","TOKEN_WILDC","TOKEN_FILE", "TOKEN_EQ", "TOKEN_EOF", "TOKEN_CMD", "TOKEN_OPT", "TOKEN_BS","TOKEN_SLASH",
	"TOKEN_DOT", "TOKEN_COMA", "TOKEN_ESP", "TOKEN_DASH", "TOKEN_HEREDOC", "TOKEN_HEREDOC_DASH", "SIMPLE_DELIM", "DQUOTED_DELIM", "SQUOTED_DELIM","TOKEN_RRED_APPEND","TOKEN_HEREDOC_STRING", "TOKEN_NL", "TOKEN_QUERY","TOKEN_AROB","TOKEN_MAX"};
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
		i++;
	}
	//printf("dq ! %d --- data = %s\n", dq, list->data);
	if (dq > 0 && dq % 2 == 0)
		return (-1); // double quote pair et dol;
	else if (dq > 0 && (dq % 2) != 0)
		return(-50);
	else 
		return (0);
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
		i++;
	}
	//printf("sq ! %d --- data = %s\n", sq, list->data);
	if (sq > 0 && sq % 2 == 0)
		return (-1); // double quote pair et dol
	else if (sq > 0 && (sq % 2) != 0)
	{
		//printf("ici\n");
		return (-100);
	}
	else 
		return (0);
}

int	check_spec_char(t_datas *token, t_dblist *list)
{
	int	i;

	i = 0;
	while (token->data[i])
	{
		if (list->infos->get_chr_c[token->data[i]] != CHR_WORD 
			&& list->infos->get_chr_c[token->data[i]] != CHR_DIGIT
				 && list->infos->get_chr_c[token->data[i]] != CHR_DASH
				 	&& list->infos->get_chr_c[token->data[i]] != CHR_DOL
					 && list->infos->get_chr_c[token->data[i]] != CHR_QUERY
					 	&& list->infos->get_chr_c[token->data[i]] != CHR_SLASH
					 		&& list->infos->get_chr_c[token->data[i]] != CHR_DOT
						 		&& list->infos->get_chr_c[token->data[i]] != CHR_UNDS
								&& list->infos->get_chr_c[token->data[i]] != CHR_RRED
									&& list->infos->get_chr_c[token->data[i]] != CHR_LRED
										&& list->infos->get_chr_c[token->data[i]] != CHR_EQ
											&& list->infos->get_chr_c[token->data[i]] != CHR_AROB
					 )
				{
					if (token->data[i] == '\'')
					{
						if	(check_squotes_dol(token) == -100)
						{
							printf("ici1\n");
							syntax_err(SYNTAX_ERR, token->data);
							return (0);
						}
						return(1);
					}
					else if (token->data[i] == '\"')
					{
						if	(check_dquotes_dol(token) == -50)
						{
							printf("ici2\n");
							syntax_err(SYNTAX_ERR, token->data);
							return (0);
						}
						return (1);
					}
					else
					{
						syntax_err(SYNTAX_ERR, token->data);
						return (0);
					}
					//return(0);
				}
			i ++;
	}
	return (1);
}

t_dblist	*token_tag(t_dblist *list)
{
	t_datas	*tag;
	t_datas	*head;
	int		aft_p;

	tag = list->first;
	head = list->first;
	aft_p = 1;
	while(tag)
	{
		if (tag->type == 5)
		{
			aft_p = 1;
			if (tag->previous && (tag->previous->type == 6 || tag->previous->type == 7 || tag->previous->type == 33))
				tag->t_token = "TOKEN_FILE";
			else if (!tag->previous || tag->previous->type == 11)
				tag->t_token = "TOKEN_CMD";
			else
				tag->t_token = "TOKEN_OPT";
			if (tag->next != NULL)
			{

				tag = tag->next;
				while (tag->type != 6 && tag->type != 7 && tag->type != 11)
				{
					tag->t_token = "TOKEN_OPT";
					tag->type = 25;
					if	(tag->next != NULL)
						tag = tag->next;
					else
						return (list) ;
				}
				if	(tag->type == 6 || tag->type == 7)
				{
					if (tag->type == 6)
					{
						if (tag->length == 2)
						{
							tag->t_token = "TOKEN_RRED_APPEND";
							tag->type = 38;
						}
					}
					if (tag->type == 7)
					{
						if (tag->length == 2)
						{
							tag->type = 33;
							tag->t_token = "TOKEN_HEREDOC";
						}
					}
					if	(tag->next == NULL)
						break ;
					tag = tag->next;
					if (tag->previous->t_token != "TOKEN_HEREDOC")
					{
						tag->type = 21;
						tag->t_token = "TOKEN_FILE";
					}
					else
					{
						if (tag->type == 5)
						{
							tag->type = 35;
							tag->t_token = "SIMPLE_DELIM";
						}
						else if (tag->type == 13)
						{
							tag->type = 36;
							tag->t_token = "DQUOTED_DELIM";
						}
						else if (tag->type == 12)
						{
							tag->type = 37;
							tag->t_token = "SQUOTED_DELIM";
						}
					}
					if (!tag->next)
						break ;	
					aft_p = 0;
				}
				else if (tag->type == 11)
				{
					if	(tag->next == NULL)
						break ;
					aft_p = 0;
				}
			}
		}
		else if (tag->type == 7)
		{
			aft_p = 1;
			if (tag->length == 2 || tag->length == 3)
			{
				if (tag->length == 2)
				{
					tag->t_token = "TOKEN_HEREDOC";
					tag->type = 33;
				}
				aft_p = 0;
				tag = tag->next;
				if (tag->type == 5)
				{
					tag->type = 35;
					tag->t_token = "SIMPLE_DELIM";
				}
				else if (tag->type == 13)
				{
					tag->type = 36;
					tag->t_token = "DQUOTED_DELIM";
				}
				else if (tag->type == 12)
				{
					tag->type = 37;
					tag->t_token = "SQUOTED_DELIM";
				}
				if (tag->next != NULL)
					tag = tag->next;
				else
					break ;
			}
			else
			{
				if (tag->next != NULL)
				{
					tag = tag->next;
					tag->t_token = "TOKEN_FILE";
					tag->type = 21;
				}
				if (tag->next != NULL && tag->next->next != NULL && (tag->previous->type != 7 && tag->previous->type != 33))
				{
					tag = tag->next;
					tag->t_token = "TOKEN_CMD";
					tag = tag->next;
				}
				if	(tag->next == NULL)
					break ;
				tag = tag->next;
			}
			while (tag->type != 6 && tag->type != 7 && tag->type != 11)
			{
				tag->t_token = "TOKEN_OPT";
				tag->type = 25;
				if	(tag->next != NULL)
					tag = tag->next;
				else
					return (list) ;
			}
			if	(tag->type == 6 || tag->type == 7)
			{
				if	(tag->next == NULL)
					break ;
				else if (tag->type == 7 && tag->length == 2)
				{
					tag->t_token = "TOKEN_HEREDOC";
					tag->type = 33;
					aft_p = 0;
					if (tag->next)
						tag = tag->next;
					else
						break ;
					if (tag->type == 5)
					{
						tag->type = 35;
						tag->t_token = "SIMPLE_DELIM";
					}
					if (tag->type == 13)
					{
						tag->type = 36;
						tag->t_token = "DQUOTED_DELIM";
					}
					if (tag->type == 12)
					{
						tag->type = 37;
						tag->t_token = "SQUOTED_DELIM";		
					}
				}
				else if (tag->type == 6 && tag->length == 2)
				{
					tag->t_token = "TOKEN_RRED_APPEND";
					tag->type = 38;
					tag = tag->next;
					tag->t_token = "TOKEN_FILE";
				}
				else 
				{
					aft_p = 0;
					tag = tag->next;
					tag->t_token = "TOKEN_FILE";
				}
			}
			else if (tag->type == 11)
			{
				if	(tag->next == NULL)
					break ;
				aft_p = 0;
			}
		}
		if	(tag->next != NULL)
			tag = tag->next;
		else
			break ;
	}
	//printf("%s\n", tag->data);
	return (list);
}

t_flist	*my_lstlast(t_flist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	my_lstadd_back(t_flist **alst, t_flist *new)
{
	t_flist	*last;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = my_lstlast(*alst);
	last -> next = new;
	new->previous = last;
	new->next = NULL;
}

t_flist *get_processes(t_dblist *list)
{
	t_flist		*finli;
	t_flist		*finli_cur;
	t_flist		*head;

	finli = init_struct_flist();
	head = finli;
	while (list->first)
	{
		while(list->first->type != 11)
		{
			//printf(" 7777 ---- data == %s - taille = %zu\n", list->first->data, ft_strlen(list->first->data));			
			create_grtoken((finli)->process, list->first->data, list->first->t_token, list->first->type);
			if	(list->first->next != NULL)
				list->first = list->first->next;
			else
				break ;
		}
		if	(list->first->next != NULL)
		{
			list->first = list->first->next;
			finli_cur = init_struct_flist();
			my_lstadd_back(&finli, finli_cur);
			finli = finli_cur;
		}
		else 
			break ;
	}
	return (head);
}

int	check_if_pathname(t_datas *data)
{
	if	(data->type == 27 && data->length > 1 && (data->data[0] == data->data[1] || data->data[1] != CHR_WORD))
	{
		isdir_err(DIR_ERR, data->data);
		return (0);
	}
	return (1);
}	

t_dblist *p_tok(t_dblist *list)
{
	t_datas	*p_list;

	p_list = list->first;
	p_list->length = ft_strlen(p_list->data);
	//affiche(list);
	if	(p_list->type != 5 && p_list->type != 13 && p_list->type != 12 && p_list->type != 7
	 && p_list->type != 1  && p_list->type != 27 && p_list->type != 28
	 	&& p_list->type != 1 || (p_list->type == 7 && p_list->length > 1))
	{
		if	(check_if_pathname(p_list) == 0)
			return (NULL);
		syntax_err(SYNTAX_ERR, p_list->data);
			return (NULL);
	}
	while(p_list)
	{
		p_list->length = ft_strlen(p_list->data);
		if	(p_list->type == 13)
		{
			if	(check_dquotes_dol(p_list) == -50)
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
		else if	(p_list->type == 12)
		{
			if	(check_squotes_dol(p_list) == -100)
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
		else if	(p_list->type == 5 || p_list->type == 31 || p_list->type == 32 
		 		|| p_list->type == 27 || p_list->type == 28 || p_list->type == 10)
		{
			// if	(check_if_pathname(p_list) == 0)
			// 	return (NULL);
			//printf("new line == %s -- %d --- %d \n", p_list->data, p_list->type, p_list->length);
			if	(check_spec_char(p_list, list) == 0)
				return (NULL);
		}
		else if (p_list->type == 11)
		{
			if	(p_list->length >= 1 && (p_list->next->type != 5 && p_list->next->type != 6 
				&& p_list->next->type != 7 && p_list->next->type != 10 && p_list->next->type != 27 && p_list->next->type != 33))
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
		else if (p_list->type == 6 || p_list->type == 7)
		{
			if (p_list->length == 2)
			{
				if (p_list->data[1] != p_list->data[0])
				{
					syntax_err(SYNTAX_ERR, p_list->data);
					return (NULL);
				}
			}
			else if (p_list->length > 2)
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
		else if	(p_list->type == 31)
		{
			if (list->first->length == 1)
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
		else
		{
			syntax_err(SYNTAX_ERR, p_list->data);
			return (NULL);
		}
		if	(p_list->next != NULL)
		 	p_list = p_list->next;
		else 
			break ;
		if	(p_list->next ==  NULL)
		{
			if	(p_list->type == 11 || p_list->type == 6 || p_list->type == 7)
			{
				syntax_err(SYNTAX_ERR, p_list->data);
				return (NULL);
			}
		}
	}
	token_tag(list);
	//affiche(list);
	return (list);
}

t_dblist	*get_tokens(char *entry)
{
	int	counter;
	unsigned int token_type;
	unsigned int token_type_cpy;
	unsigned int i;
	unsigned int j;
	int			is_dquoted;
	int			is_squoted;
	t_dblist	*list;
	t_dblist	*gr_list;
	int pos;
	char *str;
	int		k;

	i = 0;
	pos = 0;
	j = 0;
	k = 1;
	is_dquoted = 1;
	is_squoted = 1;
	list = init_linked_list();
	str = NULL;
	if (entry[0] == '\0' || list->infos->get_chr_c[entry[i]] == CHR_SP)
			return (NULL);
	while (entry[i])
	{
		token_type = list->infos->get_tok_type[list->infos->get_chr_c[entry[i]]];
		//printf("token type == %d  -- entry[i] == %c --- chr = %d\n", token_type, entry[i], list->infos->get_chr_rules[token_type][list->infos->get_chr_c[entry[i]]]);
		while (list->infos->get_chr_rules[token_type][list->infos->get_chr_c[entry[i]]] && (is_dquoted == 1 && is_squoted == 1))
		{
			if (entry[i] == '\"')
			{
				is_dquoted = 1;
				i++;
				token_type_cpy = token_type;
				while (is_dquoted == 1 && entry[i])
				{
					if (entry[i] == '\"')
					{
						//printf("caracteeeere == %c -- %d\n", entry[i], token_type);
						is_dquoted = 0;
						break ;
					}
					i++;
				}				
			}
			if (entry[i] == '\'')
			{
				is_squoted = 1;
				i++;
				token_type_cpy = token_type;
				while (is_squoted == 1 && entry[i])
				{
					if (entry[i] == '\'')
					{
						//printf("caracteeeere == %c -- %d\n", entry[i], token_type);
						is_squoted = 0;
						break ;
					}
					i++;
				}				
			}
			if (list->infos->get_chr_c[entry[i + 1]] != 1 && list->infos->get_chr_c[entry[i + 1]] != 24)
			{
				is_dquoted = 1;
				is_squoted = 1;
				i++;
			}
			else
			{
				if (list->infos->get_chr_c[entry[i + 1]] == 24)
				{
					i++;
					break ;
				}
				else
				{
					is_squoted = 1;
					is_dquoted = 1;
					i++;
				}
			}
		}
		if (token_type != 1)
		{	
			str = ft_substr(entry, j, (i - j));
			pos++;
			create_token_list(list, str, pos, token_type);
		}
		// if (is_dquoted == 1 && )
		// 	i++;
		// else 
		// 	is_dquoted = 1;
		if (entry[i + 1] != '\0' && list->infos->get_chr_c[entry[i]] != 24 && token_type != 6 && token_type != 7)
			i++;
		j = i;
	}
	affiche(list);
	if	(p_tok(list) == NULL)
		return (NULL);
	return (list);
}
