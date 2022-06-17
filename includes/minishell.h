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


extern t_glob g;

//Main functions
void			get_prompt(char **env);
char			**get_copy(char **d_tab);
t_flist			*parse_args(char	*str, char **env);
void			*get_ll(char **args);
int	       		 check_quote(char *str);
t_dblist		*get_tokens(char *entry);
t_dblist		*init_linked_list(void);
t_glob_infos	*initst_infos();
void	        init_global(void);
int 			manage_signal(void);
int				affiche(t_dblist *list); // A tej dans le futur
void			syntax_err(char *error, char *data);
void				isdir_err(char *error, char *data);
t_flist 		*get_processes(t_dblist *list);
t_flist			*init_struct_flist();
void			create_grtoken(t_dblist *l, char *data, char *tokt, int type);
void			my_lstadd_back(t_flist **alst, t_flist *new);
void			manage_one_redir(t_datas *delimiter, t_flist *gr_list);
//int				manage_multiple_redir(t_datas *delimiter, t_flist **gen_list);
int				multiple_block_p(t_flist **gr_list, int totalhd);
void			input_redir(t_datas *file);
void			output_redir(t_datas *file);
int				my_lstsize(t_flist **lst);
int	            my_lstsize_dblist(t_dblist *lst);
void			insert_node(char *repere, char *node_toadd, t_flist **head);
int				check_tot_heredoc(t_flist **list);
void			freeing_cmd(t_exec_s	exec);
void			cmd_not_found(char *error, char *cmd);
void			error_msgs(int error, char *data);
void			freeing_execution(t_exec_s	exec, int error);
void			freeing_execution_c(t_exec_c	exec, int error);
void			freeing_cmd_c(t_exec_c	exec);
int				manage_signal_hd();
void			syntax_err_file(char *error, char *data);
void				ft_sig_fork_par(int sig);
void			ft_sig_fork(int pid);
t_datas			*my_lstnew(char *data);







void	shell_parameter_expansion(t_dblist *gr_list, char **env);
char	*search_in_env_var(char *str, char **env);
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



void	child_process_simple(t_exec_s exec, t_flist *list, char **envp);
void	child_process_complex(t_exec_c exec, t_flist *list, char **envp);
char	**list_to_tab(t_dblist *list);
void	manage_exec(t_exec_c exec, t_flist *list, char **env);
void	exec_complex_cmd(t_flist *list, char **env);
int 	exec_simple_cmd(t_flist *list, char **env);
int	    exec_launcher(t_flist **list, char **env);
int		is_builtin(char *cmd);
void	exec_builtin(char **arg, char **env);

int	count_quote(char *argv);
char	**split_arg(char *argv);
int	check_arg(char *argv);
char	*get_command(char **path, char *cmd);
char	*find_path(char **envp);
void	create_pipes(t_exec_c *exec);
void	close_pipes(t_exec_c *exec);
void	manage_dup2(t_exec_c exec, int first, int second);

int    ft_cd(char **arg, char **env);
int    ft_echo(char **arg);
void    ft_env(char **arg, char **env);
void    ft_exit(char **arg);
void	ft_export(char **arg, char ***env);
void    ft_pwd(void);
void	ft_unset(char **arg, char ***env);


int		export_appreciate_symbol(char arg);
char	**dup_env_tab(char **env);
char	**env_sorted_export(char **env);
void    print_export(char **env);
//void			freeing(char *paths[])

int	manage_redirections(t_flist **li);
int	output_r(t_datas *output_r);
int	input_r(t_datas *input_r);
void delete_node(t_flist **li);
//static char	*ft_strcat(char *dest, char *src);
char    **manage_env_i(void);
char	*ft_strjoin_path(char *s1, char *s2);

void	delete_nodes_after_expansion(t_dblist *list);
void	free_char_tab(char **tab);


#endif