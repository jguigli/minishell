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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
int 			manage_signal(void);
int		affiche(t_dblist *list); // A tej dans le futur
int				pers_err_msges(char *error);
t_flist 		*get_processes(t_dblist *list);
t_flist			*init_struct_flist();
void			create_grtoken(t_dblist *l, char *data, char *tokt, int type);
void			my_lstadd_back(t_flist **alst, t_flist *new);
int				manage_one_redir(t_datas *delimiter);
int				manage_multiple_redir(t_datas *delimiter, t_flist **gen_list);
void			input_redir(t_datas *file);
void			output_redir(t_datas *file);
int				my_lstsize(t_flist **lst);





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