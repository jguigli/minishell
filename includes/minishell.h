#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structures.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

# include <sys/types.h> // a supp en doublon
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

#define OP  "ERROR OPERATOR"
#define CMD "ERROR COMMANDE"
#define OPT "ERROR OPTIONS"
#define ARG "ERROR ARGUMENTS"
#define PI  "ERROR PIPE"

//Main functions
void			get_prompt(char **env);
char			**get_copy(char **d_tab);
t_flist			*parse_args(char	*str, char **env);
void			*get_ll(char **args);
int	       		 check_quote(char *str);
t_dblist		*get_tokens(char *entry);
t_dblist		*init_linked_list(void);
t_glob_infos	*initst_infos();
int 			manage_signal(void);
int				affiche(t_dblist *list); // A tej dans le futur
int				pers_err_msges(char *error);
void			error_msgs(void);
t_flist 		*get_processes(t_dblist *list);
t_flist			*init_struct_flist();
void			create_grtoken(t_dblist *l, char *data, char *tokt, int type);
void			my_lstadd_back(t_flist **alst, t_flist *new);
char			*manage_one_redir(t_datas *delimiter, t_flist *gr_list);
//int				manage_multiple_redir(t_datas *delimiter, t_flist **gen_list);
int				multiple_block_p(t_flist **gr_list, int totalhd);
void			input_redir(t_datas *file);
void			output_redir(t_datas *file);
int				my_lstsize(t_flist **lst);
int	            my_lstsize_dblist(t_dblist *lst);
void			insert_node(char *repere, char *node_toadd, t_flist **head);
int				check_tot_heredoc(t_flist **list);





void	shell_parameter_expansion(t_dblist *gr_list, char **env);
char	*search_in_env_var(char *str, char **env);
void	set_var_in_env(char *var, char *path, char **env);
char	*case_no$_noquote(char *data, int *i, char *str);
char	*case_$_noquote(char *data, char **env, int *i, char *str);
char	*case_$bracket_noquote(char *data, char **env, int *i, char *str);
char	*case_no$_quote(char *data, int *i, char *str);
char	*case_$_quote(char *data, char **env, int *i, char *str);
char	*case_$bracket_quote(char *data, char **env, int *i, char *str);
char	*case_single_quote(char *data, int *i, char *str);
char	*manage_dquote(char *data, char **env, int *i, char *str);



void	child_process_simple(t_exec_s exec, char **arg, char **envp);
void	child_process_complex(t_exec_c exec, char **arg, char **envp);
char	**list_to_tab(t_dblist *list);
void	manage_exec(t_exec_c exec, t_flist *list, char **env);
void	exec_complex_cmd(t_flist *list, char **env);
void	exec_simple_cmd(t_flist *list, char **env);
int	    exec_launcher(t_flist **list, char **env);

int	count_quote(char *argv);
char	**split_arg(char *argv);
int	check_arg(char *argv);
char	*get_command(char **path, char *cmd);
char	*find_path(char **envp);
void	create_pipes(t_exec_c *exec);
void	close_pipes(t_exec_c *exec);
void	manage_dup2(t_exec_c exec, int first, int second);


//void			freeing(char *paths[])


#endif