#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structures.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

#define OP  "ERROR OPERATOR"
#define CMD "ERROR COMMANDE"
#define OPT "ERROR OPTIONS"
#define ARG "ERROR ARGUMENTS"
#define PI  "ERROR PIPE"

//Main functions
void			get_prompt(char **env);
char			**get_copy(char **d_tab);
void			parse_args(char	*str);
void			*get_ll(char **args);
int	       		 check_quote(char *str);
t_dblist		*get_tokens(char *entry);
t_dblist		*init_linked_list(void);
t_treenode 		*bst(t_dblist *list);
t_glob_infos	*initst_infos();
int				pers_err_msges(char *error);


//void			freeing(char *paths[])






#endif