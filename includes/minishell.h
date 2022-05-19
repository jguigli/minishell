#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structures.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

#define OP  "OPERATOR"
#define CMD "COMMANDE"
#define OPT "OPTIONS"
#define ARG "ARGUMENTS"
#define PI  "PIPE"

//Main functions
void			get_prompt(char **env);
char			**get_copy(char **d_tab);
void			parse_args(char	*str, char **env);
void			*get_ll(char **args);
int	       		 check_quote(char *str);
t_dblist		*get_tokens(char *entry);
t_dblist		*init_linked_list(void);
t_treenode 		*bst(t_dblist *list);
t_glob_infos	*initst_infos();
void	shell_parameter_expansion(t_dblist *gr_list, char **env);
int affiche(t_dblist *list);





#endif