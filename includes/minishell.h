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
#define CMD "command not found"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
#define OPT "ERROR OPTIONS"
#define SYNTAX_ERR "syntax error near unexpected token"
#define DIR_ERR "Is a directory"
#define FILE "No such file or directory"
#define PI  "ERROR PIPE"


extern int status;

//Main functions


// Signals *****
int 			manage_signal(void);
int				manage_signal_hd();
void				ft_sig_fork_par(int sig);
void			ft_sig_fork(int pid);
// *****************

// Inits *************
t_main	*init_main(void);
t_flist			*init_struct_flist();
t_dblist		*init_linked_list(void);
t_glob_infos	*initst_infos();
void	init_classes(t_glob_infos *tok_info);
void	init_tokens(t_glob_infos *tok_info);
void	init_rules(t_glob_infos *tok_info);
void	init_exec_simple(t_main *main, t_exec_s *exec);
void	init_exec_complex(t_main *main, t_exec_c *exec);

//********************


// Env ********************* 
char	*search_in_env_var(char *str, char **env);
char    **manage_env_i(void);
char	**get_copy(char **d_tab);
//*******************************

//Get_prompt ******
void			get_prompt(t_main *main);
t_dblist		*get_tokens(char *entry);
// ******************

//Parse_args
t_flist			*parse_args(char	*str, char **env);
t_flist 		*get_processes(t_dblist *list);
int				my_lstsize(t_flist *lst);
int	            my_lstsize_dblist(t_dblist *lst);
void			insert_node(char *repere, char *node_toadd, t_flist **head);
int				check_tot_heredoc(t_flist **list);
int				multiple_block_p(t_flist **gr_list, int totalhd);
void			my_lstadd_back(t_flist **alst, t_flist *new);
void			create_grtoken(t_dblist *l, char *data, char *tokt, int type);
t_datas			*my_lstnew(char *data);
// void			*get_ll(char **args);
// int	       		 check_quote(char *str);

//Errors emssages
void			syntax_err_file(char *error, char *data);
void			syntax_err(char *error, char *data);
void				isdir_err(char *error, char *data);
void			cmd_not_found(char *error, char *cmd);
void			error_msgs(int error, char *data);
// **************************** 

// Affichage *****************
int				affiche(t_dblist *list); // A tej dans le futur
// *******************

//heredoc *****************
void			manage_one_redir(t_datas *delimiter, t_flist *gr_list);
// *********************

// Redir *********
int		manage_multiple_redir(t_datas *delimiter, t_flist **gen_list);
void			input_redir(t_datas *file, t_main *main);
void			output_redir(t_datas *file, t_main *main);
// *************

void			freeing_cmd(t_exec_s	exec);
void			freeing_execution(t_exec_s	exec, int error);
void			freeing_execution_c(t_exec_c	exec, int error);
void			freeing_cmd_c(t_exec_c	exec);

// Expansion ***************
void	shell_parameter_expansion(t_dblist *gr_list, char **env);
char	**set_var_in_env(char *var, char *path, char **env);
char	*case_nodol_noquote(char *data, int *i, char *str);
char	*case_dol_noquote(char *data, char **env, int *i, char *str);
char	*case_dolbracket_noquote(char *data, char **env, int *i, char *str);
char	*case_nodol_quote(char *data, int *i, char *str);
char	*case_dol_quote(char *data, char **env, int *i, char *str);
char	*case_dolbracket_quote(char *data, char **env, int *i, char *str);
char	*case_single_quote(char *data, int *i, char *str);
char	*manage_dquote(char *data, char **env, int *i, char *str);
char    *case_status(int *i, char *str);
char	*case_dolafterdol(int *i, char *str);
//* ********************************************

// Executon **************************
int	    exec_launcher(t_main *main);
void	exec_complex_cmd(t_main *main);
void	child_process_complex(t_exec_c exec, t_flist *list, t_main *main);
char	**list_to_tab(t_dblist *list);
void	manage_exec(t_exec_c exec, t_main *main);
void	manage_child_complex(t_exec_c exec, t_flist *list, t_main *main);
void	child_process_simple(t_exec_s exec, t_flist *list, t_main *main);
int 	exec_simple_cmd(t_main *main);
int		is_builtin(char *cmd);
void	exec_builtin(char **arg, t_main *main);
int	count_quote(char *argv);
char	**split_arg(char *argv);
int	check_arg(char *argv);
char	*get_command(char **path, char *cmd);
char	*find_path(char **envp);
void	create_pipes(t_exec_c *exec);
void	close_pipes(t_exec_c *exec);
void	manage_dup2(t_exec_c exec, int first, int second);
void	delete_nodes_after_expansion(t_dblist *list);
// ***********************************************

// Builtin ************
int    ft_cd(char **arg, t_main *main);
int    ft_echo(char **arg);
void    ft_env(char **arg, char **env);
void    ft_exit(char **arg);
void	ft_export(char **arg, t_main *main);
void    ft_pwd(void);
void	ft_unset(char **arg, t_main *main);
// *********************

int		export_appreciate_symbol(char arg);
char	**dup_env_tab(char **env);
char	**env_sorted_export(char **env);
void    print_export(char **env);
void	free_char_tab(char **tab);
// void			freeing(char *paths[])

int	manage_redirections(t_flist **li, t_main *main);
void delete_node(t_flist **li);

// Ext_funtions *********************
// //static char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin_path(char *s1, char *s2);
// **********************

// Free *******************************


// ************************************


#endif