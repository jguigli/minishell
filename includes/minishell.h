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
void		get_prompt(char **env);
char		**get_copy(char **d_tab);
void		parse_args(char	*str);
t_blocks	*fromtab_toll(char **args);
void		*get_ll(char **args);
void	init_struct(t_glob *global);
int	check_quote(char *str);
int	get_tokens(char *entry);



#endif