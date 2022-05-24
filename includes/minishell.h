#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structures.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include <signal.h>

#define OP  "ERROR OPERATOR"
#define CMD "ERROR COMMANDE"
#define OPT "ERROR OPTIONS"
#define ARG "ERROR ARGUMENTS"
#define PI  "ERROR PIPE"

//Main functions
void			get_prompt(char **env);
char			**get_copy(char **d_tab);
void			parse_args(char	*str, char **env);
void			*get_ll(char **args);
int	       		 check_quote(char *str);
t_dblist		*get_tokens(char *entry);
t_dblist		*init_linked_list(void);
t_glob_infos	*initst_infos();
int manage_signal(void);
int affiche(t_dblist *list); // A tej dans le futur
int				pers_err_msges(char *error);

void	shell_parameter_expansion(t_dblist *gr_list, char **env);
char	*search_in_env_var(char *str, char **env);
char	*case_no$_noquote(char *data, int *i, char *str);
char	*case_$_noquote(char *data, char **env, int *i, char *str);
char	*case_$bracket_noquote(char *data, char **env, int *i, char *str);
char	*case_no$_quote(char *data, int *i, char *str);
char	*case_$_quote(char *data, char **env, int *i, char *str);
char	*case_$bracket_quote(char *data, char **env, int *i, char *str);
char	*case_single_quote(char *data, int *i, char *str);
char	*manage_dquote(char *data, char **env, int *i, char *str);



//void			freeing(char *paths[])


#endif