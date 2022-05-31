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
	// printf("DATA =  %s\n", current->data);
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
	"TOKEN_DOT", "TOKEN_COMA", "TOKEN_ESP", "TOKEN_DASH", "TOKEN_MAX"};
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
					 	&& list->infos->get_chr_c[token->data[i]] != CHR_SLASH
					 		&& list->infos->get_chr_c[token->data[i]] != CHR_DOT
						 		&& list->infos->get_chr_c[token->data[i]] != CHR_UNDS
							 		&& list->infos->get_chr_c[token->data[i]] != CHR_DQUOTE
								 		&& list->infos->get_chr_c[token->data[i]] != CHR_SQUOTE
										 		&& list->infos->get_chr_c[token->data[i]] != CHR_RRED
								 					&& list->infos->get_chr_c[token->data[i]] != CHR_LRED
					 )
				 {
					pers_err_msges(ARG);
				 }
		i ++;
	}
	return (0);
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
		//printf("A ANALYSER %s\n", tag->data);
		if (tag->type == 5)
		{
			aft_p = 1;
			tag->t_token = "TOKEN_CMD";
			if (tag->next != NULL)
			{

				tag = tag->next;
				//printf("ICI 1  %s --- %s\n", tag->data, tag->t_token);
				while (tag->type != 6 && tag->type != 7 && tag->type != 11)
				{
					//printf("test 73\n");
					tag->t_token = "TOKEN_OPT";
					tag->type = 25;
					if	(tag->next != NULL)
						tag = tag->next;
					else
						return (list) ;
				}
				// printf("data ===> %s --- %d\n", tag->data, tag->type);
				if	(tag->type == 6 || tag->type == 7)
				{
					//printf("ICI 2  %s -- %s -- %d -- %d\n", tag->data, tag->t_token, tag->length, tag->type);
					if (tag->type == 6)
					{
						if (tag->length == 2)
						{
							//printf("test 74\n");
							tag->t_token = "TOKEN_RRED_APPEND";
							tag->type = 38;
						}
					}
					if (tag->type == 7)
					{
						//printf("75 %s -- %s -- %d -- %d\n", tag->data, tag->t_token, tag->length, tag->type);
						if (tag->length == 2)
						{
							tag->type = 33;
							tag->t_token = "TOKEN_HEREDOC";
						}
					}
					//printf("ici 1 \n");
					if	(tag->next == NULL)
						break ;
					//printf("test 76\n");
					tag = tag->next;
					//printf("ici 2 %s -- %s\n", tag->data, tag->previous->data);
					// if (tag->next == NULL)
					// {
					if (tag->previous->t_token != "TOKEN_HEREDOC")
					{
						//printf("test 77\n");
						tag->type = 21;
						tag->t_token = "TOKEN_FILE";
					}
					else
					{
						//printf("ici 78%s -- %d\n", tag->data, tag->type);
						if (tag->type == 5)
						{
							//printf("test 79\n");
							tag->type = 35;
							tag->t_token = "SIMPLE_DELIM";
						}
						else if (tag->type == 13)
						{
							//printf("test 80\n");
							tag->type = 36;
							tag->t_token = "DQUOTED_DELIM";
						}
						else if (tag->type == 12)
						{
							//printf("test 81\n");
							tag->type = 37;
							tag->t_token = "SQUOTED_DELIM";
						}
					}
					//printf("82%s\n", tag->t_token);
					if (!tag->next)
						break ;	
					// }
					aft_p = 0;
					printf("83 %s ---> %s\n", tag->data, tag->t_token);
				}
				else if (tag->type == 11)
				{
					//printf("ici 84\n");
					if	(tag->next == NULL)
						break ;
					aft_p = 0;
					// tag = tag->next;
				}
			}
		}
		else if (tag->type == 7)
		{
			//printf("iciiiiii ==> %s \n", tag->next->data);
			aft_p = 1;
			if (tag->length == 2 || tag->length == 3)
			{
				//printf("ici 85\n");
				//printf(" 6666 ---> %s -- %d\n", tag->data, tag->type);
				if (tag->length == 2)
				{
					//printf(" 7777 ---> %s -- %d\n", tag->data, tag->type);
					//printf("ici 86\n");
					tag->t_token = "TOKEN_HEREDOC";
					tag->type = 33;
				}
				aft_p = 0;
				//printf("ici 87\n");
				tag = tag->next;
				//printf(" 888888 ---> %s -- %d\n", tag->data, tag->type);
				//tag->t_token = "TOKEN_HEREDOC_DELIM";
					//tag = tag->next;
				if (tag->type == 5)
				{
					//printf("ici 88\n");
					tag->type = 35;
					tag->t_token = "SIMPLE_DELIM";
				}
				else if (tag->type == 13)
				{
					//printf("ici 89\n");
					tag->type = 36;
					tag->t_token = "DQUOTED_DELIM";
				}
				else if (tag->type == 12)
				{
					//printf("ici 90\n");
					tag->type = 37;
					tag->t_token = "SQUOTED_DELIM";
				}
				if (tag->next != NULL)
					tag = tag->next;
				else
					break ;
				//printf("hereuuuh %s ---- %d\n", tag->data, tag->type);
			}
			else
			{
				if (tag->next != NULL)
				{
					//printf("ici 91\n");
					tag = tag->next;
					tag->t_token = "TOKEN_FILE";
					tag->type = 21;
				}
				if (tag->next != NULL && tag->next->next != NULL)
				{
					//printf("ici 92\n");
					tag = tag->next;
					tag->t_token = "TOKEN_CMD";
					tag = tag->next;
				}
				else
					break ;
			}
			while (tag->type != 6 && tag->type != 7 && tag->type != 11)
			{
				tag->t_token = "TOKEN_OPT";
				tag->type = 25;
				if	(tag->next != NULL)
				{
					//printf("ici 93\n");
					tag = tag->next;
				}
				else
					return (list) ;
			}
			// printf("%s\n", tag->data);
			if	(tag->type == 6 || tag->type == 7)
			{
				if	(tag->next == NULL)
					break ;
				else if (tag->type == 7 && tag->length == 2)
				{
					tag->t_token = "TOKEN_HEREDOC";
					tag->type = 33;
					aft_p = 0;
					//printf("ici 93\n");
					if (tag->next)
						tag = tag->next;
					else
						break ;
					// tag->t_token = "TOKEN_HEREDOC";
					// tag->type = 33;
					if (tag->type == 5)
					{
						//printf("ici 94\n");
						tag->type = 35;
						tag->t_token = "SIMPLE_DELIM";
					}
					if (tag->type == 13)
					{
						//printf("ici 95\n");
						tag->type = 36;
						tag->t_token = "DQUOTED_DELIM";
					}
					if (tag->type == 12)
					{
						//printf("ici 96\n");
						tag->type = 37;
						tag->t_token = "SQUOTED_DELIM";		
					}
				}
				else
				{
					//printf("ici 97\n");
					aft_p = 0;
					tag = tag->next;
					tag->t_token = "TOKEN_FILE";
				}
			}
			else if (tag->type == 11)
			{
				//printf("ici 97\n");
				if	(tag->next == NULL)
					break ;
				aft_p = 0;
				// tag = tag->next;
			}
		}
		// printf("dataaa herev--> %s\n", tag->data);
		if	(tag->next != NULL)
		{
			//printf("ici 98\n");
			tag = tag->next;
		}
		else
		{
			//printf("ici 99\n");
			break ;
		}
	}
	//printf("ici 100\n");
	affiche(list);
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

	//affiche(list);
	finli = init_struct_flist();
	head = finli;
	while (list->first)
	{
		while(list->first->type != 11)
		{
			//finli->process = list;
			//printf("data --> %s -- t_token = %s\n", list->first->data, list->first->t_token);
			create_grtoken((finli)->process, list->first->data, list->first->t_token, list->first->type);
			if	(list->first->next != NULL)
				list->first = list->first->next;
			else
				break ;
		}
		//my_lstadd_back(head, (finli));
		if	(list->first->next != NULL)
		{
			list->first = list->first->next;
			finli_cur = init_struct_flist();
			my_lstadd_back(&finli, finli_cur);
			//printf("phrase --> %d\n", finli->next->number);
			finli = finli_cur;
		}
		else 
			break ;
	}
	//return (finli);
	return (head);
}

t_dblist *p_tok(t_dblist *list)
{
	t_datas	*p_list;

	p_list = list->first;
	if	(p_list->type != 5 && p_list->type != 13 && p_list->type != 12 && p_list->type != 7 && p_list->type != 1  && p_list->type != 27 && p_list->type != 28)
		pers_err_msges(ARG);
	while(p_list)
	{
		//printf("token a analyser ---> %s \n", p_list->data);
		p_list->length = ft_strlen(p_list->data);
		if	(p_list->type == 13)
		{
			//printf("ici 1 \n");
			if	(check_dquotes_dol(p_list) == -1)
			{
				list->first->dq = 1;
				list->first->dol = 1;
			}
			else if (check_dquotes_dol(p_list) == -2)
			{
				//printf("ici 2 \n");
				list->first->dq = 1;
				list->first->dol = 0;
			}
			else if (check_dquotes_dol(p_list) > 1)
			{
				//printf("ici 3 \n");
				list->first->dq = 1;
				list->first->dol = check_dquotes_dol(p_list);
			}
			else
			{
				//printf("ici 4\n");
				pers_err_msges(ARG);
			}
		}
		else if	(p_list->type == 12)
		{
			if	(check_squotes_dol(p_list) == -1)
			{
				//printf("ici 5\n");
				list->first->dq = 1;
				list->first->dol = 1;
			}
			else if (check_squotes_dol(p_list) == -2)
			{
				//printf("ici 6\n");
				list->first->dq = 1;
				list->first->dol = 0;
			}
			else if (check_squotes_dol(p_list) > 1)
			{
				//printf("ici 7\n");
				list->first->dq = 1;
				list->first->dol = check_squotes_dol(p_list);
			}
			else
			{
				//printf("ici 8\n");
				pers_err_msges(ARG);
			}
		}
		else if	(p_list->type == 5 || p_list->type == 31 || p_list->type == 32 
		 		|| p_list->type == 27 || p_list->type == 28 || p_list->type == 10)
		{
			//printf("ici 9 --> %s\n", p_list->data);
			check_spec_char(p_list, list);
		}
		else if (p_list->type == 11)
		{
			if	(p_list->length != 1)
			{
				//printf("ici 10\n");
				pers_err_msges(ARG);
			}
		}
		else if (p_list->type == 6 || p_list->type == 7)
		{
			if (p_list->length == 2)
			{
				if (p_list->data[1] != p_list->data[0])
				{
					//printf("ici 11\n");
					pers_err_msges(ARG);
				}
			}
			// else if (p_list->length > 2)
			// {
			// 	if ((p_list->data[1] != p_list->data[0]) && (p_list->data[2] != CHR_WORD && p_list->data[2] != CHR_DIGIT && p_list->data[2] != CHR_DASH))
			// 	{
			// 		 //printf("ici 11\n");
			// 		pers_err_msges(ARG);
			// 	}
			// 	p_list->redir = 2;
			// }
			// else if (p_list->data[1] != p_list->data[0] && p_list->data[2] != CHR_DASH)
			// {
			// 	 //printf("ici 12\n");
			// 	pers_err_msges(ARG);
			// }
			else if (p_list->length >= 2)
				pers_err_msges(ARG);
		}
		else if	(p_list->type == 31)
		{
			if (list->first->length == 1)
				pers_err_msges(ARG);
		}
		else
		{
			pers_err_msges(ARG);
		}
		if	(p_list->next != NULL)
		 	p_list = p_list->next;
		else 
			break ;
		// printf("token = %s -- %s\n", p_list->data, p_list->t_token);
		if	(p_list->next ==  NULL)
		{
			if	(p_list->type == 11 || p_list->type == 6 || p_list->type == 7)
			{
				 //printf("ici 14\n");
				pers_err_msges(ARG);
			}
		}
	}
	// printf("dataaa == %s\n", list->first->data);
	affiche(list);
	token_tag(list);
	//get_processes(list);
	return (list);
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
	t_dblist	*gr_list;
	int pos;

	i = 0;
	pos = 0;
	j = 0;
	is_quoted = 1;
	list = init_linked_list();
	p_list = init_linked_list();
	char *str;

	if (entry[0] == '\0')
			return (NULL);
	while (entry[i])
	{
		token_type = list->infos->get_tok_type[list->infos->get_chr_c[entry[i]]];
		//printf("%d ---- %c\n", token_type, entry[i]);
		while (list->infos->get_chr_rules[token_type][list->infos->get_chr_c[entry[i]]] && is_quoted == 1)
		{
			//printf(" ICI 1 == %d ---- %c\n", token_type, entry[i]);
			if (entry[i] == '\"' && list->infos->get_tok_type[list->infos->get_chr_c[entry[i - 1]]] == 1)
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
			if (entry[i] == '\'' && list->infos->get_tok_type[list->infos->get_chr_c[entry[i - 1]]] == 1)
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
		//printf(" ICI 2 == %d ---- %c --- %d\n", token_type, entry[i], i);
		if (token_type != 1) // MODIF
		{	
			str = ft_substr(entry, j, (i - j));
			pos++;
			create_token_list(list, str, pos, token_type);
		}
		// printf(" str == %s \n", str);
		if (entry[i] == '\0')
			break ;
		if (is_quoted == 1 && list->infos->get_chr_c[entry[i]] != 22 && token_type != 6 && token_type != 7)
			i++;
		else 
			is_quoted = 1;
		j = i;
		//printf("entry [i] fin de boucle--- == %c ---- j = %d, i == %d\n", entry[i], j, i);
	}
	//affiche(list);
	p_tok(list);
	return (list);
}