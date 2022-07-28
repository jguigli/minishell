/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:25:38 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 21:26:45 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "structures.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <string.h>

# define OP  "ERROR OPERATOR"
# define CMD "command not found"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define OPT "ERROR OPTIONS"
# define SYNTAX_ERR "syntax error near unexpected token"
# define IDENTIFIER "not a valid identifier"
# define DIR_ERR "Is a directory"
# define FILE "No such file or directory"
# define PI  "ERROR PIPE"
# define AMBIG "ambiguous redirect"
# define OPTION "invalid option"
# define NUMARG "numeric argument required"
# define CD "cd"
# define EXPORT "export"
# define ECHO "echo"
# define ENV "env"
# define EXIT "exit"
# define PWD "pwd"
# define UNSET "unset"
# define PERMISSION "Permission denied"

extern int	g_status;

int				manage_signal(void);
int				manage_sig_in_forks(pid_t pid, t_main *main);
t_main			*init_main(void);
t_flist			*init_struct_flist(void);
t_dblist		*init_linked_list(void);
t_glob_infos	*initst_infos(void);
void			init_classes(t_glob_infos *tok_info);
void			init_tokens(t_glob_infos *tok_info);
void			init_rules(t_glob_infos *tok_info);
void			init_types(t_glob_infos *tok_info);
void			init_exec_simple(t_main *main, t_exec_s *exec);
void			init_exec_complex(t_main *main, t_exec_c *exec);
char			*search_in_env_var(char *str, char **env);
int				search_var_tab(char *var, char **tab);
char			**manage_env_i(void);
char			**get_copy(char **d_tab);
void			get_prompt(t_main *main);
t_dblist		*get_tokens(char *entry);
int				main_loop(t_dblist **list, char *e, char *str);
int				first_checks(t_dblist **list, char *e);
int				increment_or_no(t_dblist **list, char *e);
int				create_str(t_dblist **list, char *e, char *str);
int				is_squoted(t_dblist **list, char *e);
int				squoted_loop(t_dblist *l, char *e);
int				is_quoted_redir(t_dblist *l, char *e);
int				is_not_space(t_dblist *l, char *e);
int				manage_quote(t_dblist **list, char *e);
int				check_start_ws(t_dblist **list, char *e);
int				check_fichar(t_dblist **list, char *e);
int				is_dquoted(t_dblist **list, char *e);
t_dblist		*cr_first_elem(t_dblist **list, char *s,
					unsigned int t, t_datas *element);
t_dblist		*cr_grfiel(t_dblist **list, char *s,
					unsigned int t, t_datas *element);
t_dblist		*cr_other_elem(t_dblist **list, char *s,
					unsigned int t, t_datas *element);
int				check_if_pathname(t_datas *data, t_dblist *list);
int				first_char(t_datas *p_list);
int				is_pipe(t_datas *p_list);
int				is_redir(t_datas *p_list);
int				is_dot(t_datas *p_list, t_dblist *list);
int				check_nodes(t_datas *p_list, t_dblist *list);
t_dblist		*p_tok(t_dblist *list);
int				check_nonprintablechar(char *p_list);
int				beginning(t_datas *tag, t_datas *head);
void			is_option(t_datas *tag, t_dblist *list);
t_datas			*option_loop(t_datas *tag, t_dblist *list, int choix);
void			heredoc_or_append(t_datas *tag, t_dblist *list);
void			is_file(t_datas *tag, t_dblist *list, int choix);
void			is_rred_append(t_datas *tag, t_dblist *list, int choix);
void			is_dq_delim(t_datas *tag, t_dblist *list, int choix);
void			is_sq_delim(t_datas *tag, t_dblist *list, int choix);
void			is_simple_delim(t_datas *tag, t_dblist *list, int choix);
t_datas			*file_or_delim(t_datas *tag, t_dblist *list);
t_datas			*op_is_redir_or_pipe(t_datas *tag, t_dblist *list);
t_datas			*after_word(t_datas *tag, t_dblist *list);
t_datas			*is_word(t_datas *tag, t_dblist *list, t_datas *head);
void			is_heredoc(t_datas *tag, t_dblist *list);
t_datas			*word_after_delim(t_datas *tag, t_dblist *list);
t_datas			*heredoking(t_datas *tag, t_dblist *list);
t_datas			*lred_heredoc(t_datas *tag, t_dblist *list);
void			check_previous(t_datas *tag, t_dblist *list);
t_datas			*not_heredoking(t_datas *tag, t_dblist *list);
t_datas			*redir_after_hd(t_datas *tag, t_dblist *list);
t_datas			*is_lred(t_datas *tag, t_dblist *list, t_datas *head);
t_datas			*is_rred(t_datas *tag, t_dblist *list);
t_datas			*is_redirection(t_datas *tag, t_dblist *list, t_datas *head);
t_datas			*making_tags(t_datas *tag, t_dblist *list, t_datas *head);
t_dblist		*token_tag(t_dblist *list);
void			rules_for_others(t_glob_infos *tok_info);
void			rules_for_colon(t_glob_infos *tok_info);
void			rules_for_diez(t_glob_infos *tok_info);
void			rules_for_rbracket(t_glob_infos *tok_info);
void			rules_for_lbracket(t_glob_infos *tok_info);
void			rules_for_dash(t_glob_infos *tok_info);
void			rules_for_dot(t_glob_infos *tok_info);
void			rules_for_coma(t_glob_infos *tok_info);
void			rules_for_semi(t_glob_infos *tok_info);
void			rules_for_esp(t_glob_infos *tok_info);
void			rules_for_bslash(t_glob_infos *tok_info);
void			rules_for_slash(t_glob_infos *tok_info);
void			rules_for_squote(t_glob_infos *tok_info);
void			rules_for_dquote(t_glob_infos *tok_info);
void			rules_for_dol_bis(t_glob_infos *tok_info);
void			rules_for_dol(t_glob_infos *tok_info);
void			rules_for_pipe(t_glob_infos *tok_info);
void			rules_for_rbrace_bis(t_glob_infos *tok_info);
void			rules_for_rbrace(t_glob_infos *tok_info);
void			rules_for_lbrace_bis(t_glob_infos *tok_info);
void			rules_for_lbrace(t_glob_infos *tok_info);
void			rules_for_space(t_glob_infos *tok_info);
void			rules_for_bang(t_glob_infos *tok_info);
void			rules_for_lred(t_glob_infos *tok_info);
void			rules_for_rred(t_glob_infos *tok_info);
void			rules_for_word_bis(t_glob_infos *tok_info);
void			rules_for_word(t_glob_infos *tok_info);
void			init_tokens(t_glob_infos *tok_info);
void			init_tokens_fifty(t_glob_infos *tok_info);
void			init_tokens_twentyfive(t_glob_infos *tok_info);
void			init_classes(t_glob_infos *tok_info);
void			init_ninety(t_glob_infos *tok_info);
void			init_seventyfive(t_glob_infos *tok_info);
void			init_fifty(t_glob_infos *tok_info);
void			init_twenty_five(t_glob_infos *tok_info);
void			init_twenty_five(t_glob_infos *tok_info);
void			init_fifty(t_glob_infos *tok_info);
void			init_seventyfive(t_glob_infos *tok_info);
void			init_classes(t_glob_infos *tok_info);
void			init_ninety(t_glob_infos *tok_info);
void			init_tokens_twentyfive(t_glob_infos *tok_info);
void			init_tokens_fifty(t_glob_infos *tok_info);
void			init_tokens(t_glob_infos *tok_info);
void			rules_for_word(t_glob_infos *tok_info);
void			rules_for_word_bis(t_glob_infos *tok_info);
void			rules_for_rred(t_glob_infos *tok_info);
void			rules_for_lred(t_glob_infos *tok_info);
void			rules_for_bang(t_glob_infos *tok_info);
void			rules_for_space(t_glob_infos *tok_info);
void			rules_for_lbrace(t_glob_infos *tok_info);
void			rules_for_lbrace_bis(t_glob_infos *tok_info);
void			rules_for_rbrace(t_glob_infos *tok_info);
void			rules_for_rbrace_bis(t_glob_infos *tok_info);
void			rules_for_pipe(t_glob_infos *tok_info);
void			rules_for_dol(t_glob_infos *tok_info);
void			rules_for_dol_bis(t_glob_infos *tok_info);
void			rules_for_dquote(t_glob_infos *tok_info);
void			_for_squote(t_glob_infos *tok_info);
void			rules_for_slash(t_glob_infos *tok_info);
void			rules_for_bslash(t_glob_infos *tok_info);
void			rules_for_esp(t_glob_infos *tok_info);
void			rules_for_semi(t_glob_infos *tok_info);
void			rules_for_coma(t_glob_infos *tok_info);
void			rules_for_dot(t_glob_infos *tok_info);
void			rules_for_dash(t_glob_infos *tok_info);
void			rules_for_lbracket(t_glob_infos *tok_info);
void			rules_for_rbracket(t_glob_infos *tok_info);
void			rules_for_diez(t_glob_infos *tok_info);
void			rules_for_colon(t_glob_infos *tok_info);
void			rules_for_others(t_glob_infos *tok_info);
void			init_rules(t_glob_infos *tok_info);
char			*sb_get_hdstring(t_main *main, t_datas *list, t_flist *head);
void			reset_main_values(t_main *main);
void			cb_reset_main_values(t_main *main);
t_datas			*insertn_getnext_hd(t_datas *list, t_main *main, t_flist *head);
int				sb_main_loop(t_flist *head, t_main *main, t_datas *list,
					t_flist *head2);
int				simple_block_p(t_flist **gr_list, t_main *main);
t_flist			*complexcmd_gethd(t_flist *head);
void			cb_child_process(t_datas *list, t_flist *head,
					t_main *main, t_flist *head2);
char			*cb_get_hdstring(t_main *main, t_datas *list, t_flist *head);
t_datas			*cb_loop(t_datas *list);
t_datas			*cb_getnext_hd(t_datas *list, t_main *main, t_flist *head);
void			*cb_nextflistnode(t_main *main, t_flist *head, t_datas *list);
int				cb_mainloop(t_flist *head, t_main *main, t_datas *list,
					t_flist *head2);
int				multiple_block_p(t_flist **gr_list, int totalhd, t_main *main);
int				check_tot_heredoc(t_flist **list);
int				check_if_redir_only(t_datas *data, t_flist **li);
t_datas			*cr_blocks(t_datas *data, t_flist *finli, t_datas *to_free);
t_datas			*get_next_andfree(t_datas *data, t_datas *to_free);
t_flist			*get_processes(t_dblist *list);
void			freeing_dblist(t_dblist *fin_li);
t_flist			*simple_cmd(t_flist *gr_list, t_main *main);
t_flist			*complex_cmd(t_flist *gr_list, t_main *main);
int				get_signal(t_main *main, int wstatus, int pid, int tot_pid);
t_flist			*parse_args(char	*str, t_main *main);
void			count_redir(t_datas *list, t_flist **head, int pos);
void			count_heredoc_append_opt(t_datas *list,
					t_flist **head, int pos);
void			counting(t_flist **gr_list);
int				my_lstsize(t_flist *lst);
int				my_lstsize_dblist(t_dblist *lst);
void			insert_node(char *repere, char *node_toadd, t_flist **head);
void			my_lstadd_back(t_flist **alst, t_flist *new);
void			create_grtoken(t_dblist *l, char *data, char *tokt, int type);
void			create_token_list(t_dblist *l, char *s, unsigned int t);
t_datas			*my_lstnew(char *data);
t_flist			*my_lstlast(t_flist *lst);
void			my_lstadd_back(t_flist **alst, t_flist *new);
int				check_if_redir_only(t_datas *data, t_flist **li);
int				check_if_redir_only_manage(t_datas *data, t_flist **li);
void			free_exec_complex_child(t_exec_c *exec);
int				waiting_child_hd(pid_t fi, t_main *main, int i, int tothd);
int				get_signal(t_main *main, int wstatus, int pid, int tot_pid);
int				waiting_child_exec(pid_t fi, t_main *main,
					int pid, int tot_pid);
t_datas			*gettohd(t_datas *list);
int				count_quote(char *argv);
char			*hd_removedquote(char *str);
char			*hd_expansion(char *str, t_main *main);
char			*if_is_no_quoted(char *str, char *rep, int i, int j);
char			*if_is_dquoted(char *str, char *rep, int *i, int j);
char			*if_is_squoted(char *str, char *rep, int *i, int j);
char			*if_is_no_dol(char *str, char *rep, int i, int j);
char			*if_is_dol(char *str, char *rep, int *i, char **env);
int				output_r(t_datas *output_r, t_main *main);
void			close_openfds(t_main *main);
int				ipr_islred(t_datas *input_r, t_main *main);
int				input_r(t_datas *input_r, t_main *main);
t_datas			*delnode_empty(t_datas *current, t_flist *list);
t_datas			*is_rred_app(t_datas *current, t_main *main);
void			delete_node(t_flist **li);
void			delnode_mainloop(t_datas *current, t_flist *list);
t_datas			*delnode_fir_empty(t_datas *current, t_flist *list);
t_datas			*delnode_nextok(t_datas *current, t_flist *list);
void			syntax_err_file(char *error, char *data);
void			syntax_err(char *error, char *data);
void			syntax_err_identifier(char *error, char *data);
void			isdir_err(char *error, char *data);
void			cmd_not_found(char *error, char *cmd);
void			error_msgs(int error, char *data);
void			error_msg_redir(char *data, char *error);
void			syntax_err_option(char *function, char *data, char *error);
void			syntax_err_builtin(char *function, char *data, char *error);
void			err_chdir(char *function, char *data);
void			manage_one_redir(t_datas *delimiter, t_flist *gr_list,
					t_flist *head2, t_main *main);
int				manage_multiple_redir(t_datas *delimiter, t_flist **gen_list);
void			input_redir(t_datas *file, t_main *main);
void			output_redir(t_datas *file, t_main *main);
int				shell_parameter_expansion(t_dblist *gr_list, char **env);
char			*add_char_around(char *s1, char c);
char			**set_var_in_env(char *var, char *path, char **env);
char			*case_nodol_noquote(char *data, int *i, char *str);
char			*case_dol_noquote(char *data, char **env, int *i, char *str);
char			*case_dolbracket_noquote(char *data, char **env,
					int *i, char *str);
char			*case_nodol_quote(char *data, int *i, char *str);
char			*case_dol_quote(char *data, char **env, int *i, char *str);
char			*case_dolbracket_quote(char *data, char **env,
					int *i, char *str);
char			*case_single_quote(char *data, int *i, char *str);
char			*manage_dquote(char *data, char **env, int *i, char *str);
char			*case_g_status(int *i, char *str);
char			*case_dolafterdol(int *i, char *str);
char			*case_digit(char *data, int *i, char *str);
t_datas			*word_splitting(t_dblist *gr_list, t_datas *list);
void			quote_removal(t_dblist *gr_list);
int				exec_launcher(t_main *main);
void			exec_complex_cmd(t_main *main);
void			child_process_complex(t_exec_c exec, t_flist *list,
					t_main *main);
char			**list_to_tab(t_dblist *list);
void			manage_exec(t_exec_c exec, t_main *main);
void			manage_child_complex(t_exec_c exec, t_flist *list,
					t_main *main);
void			child_process_simple(t_exec_s exec, t_flist *list,
					t_main *main);
int				exec_simple_cmd(t_main *main);
int				is_builtin(char *cmd);
void			exec_builtin(char **arg, t_main *main);
int				count_quote(char *argv);
char			**split_arg(char *argv);
int				check_arg(char *argv);
char			*get_command(char **path, char *cmd);
char			*find_path(char **envp);
void			create_pipes(t_exec_c *exec);
void			close_pipes(t_exec_c *exec);
void			manage_dup2(t_exec_c exec, int first, int second);
void			delete_nodes_after_expansion(t_dblist **list);
int				ft_cd(char **arg, t_main *main);
int				ft_echo(char **arg);
void			ft_env(char **arg, char **env);
void			ft_exit(char **arg, t_main *main);
void			ft_export(char **arg, t_main *main);
void			ft_pwd(char **arg);
void			ft_unset(char **arg, t_main *main);
int				export_appreciate_symbol(char arg);
char			**dup_env_tab(char **env);
char			**dup_env_tab_export(char **env);
char			**env_sorted_export(char **env);
void			print_export(t_main *main);
void			free_char_tab(char **tab);
void			put_in_export_tab(char *arg, t_main *main);
void			replace_var_tab_env(char *arg, t_main *main);
void			replace_var_tab_export(char *arg, t_main *main);
void			export_var_env(char *arg, t_main *main);
char			*ft_dup_without_plus(char *arg);
char			*ft_dup_plus(char *arg, char *line);
void			export_var_env_plus(char *arg, t_main *main);
void			put_in_export_tab_plus(char *arg, t_main *main);
void			replace_var_tab_env_plus(char *arg, t_main *main);
void			replace_var_tab_export_plus(char *arg, t_main *main);
int				search_var_tab_plus(char *var, char **tab);
int				cd_home(t_main *main);
int				cd_oldpwd(t_main *main);
char			**unset_var_env(int position, char **env);
char			**unset_var_export(int position, char **export);
int				change_directory(char *data, t_main *main);
void			check_pwd_path(t_main *main);
void			check_oldpwd_path(t_main *main);
int				manage_redirections(t_flist **li, t_main *main);
void			delete_node(t_flist **li);
int				waiting_child_hd(pid_t fi, t_main *main, int i, int tothd);
int				waiting_child_exec(pid_t fi, t_main *main, int pid, int nb_pid);
char			*ft_strjoin_path(char *s1, char *s2);
void			freeing_cmd(t_exec_s	*exec);
void			freeing_execution(t_exec_s	exec, int error);
void			freeing_execution_c(t_exec_c	exec, int error);
void			freeing_cmd_c(t_exec_c	*exec);
void			ft_free(t_main *main);
void			free_flist(t_flist	*first);
void			free_dblist(t_dblist *first);
void			free_datas(t_datas *data);
void			free_exec_simple(t_exec_s *exec);
void			free_exec_complex(t_exec_c *exec);
int				fork_fail(int fi);
void			go_heredoc(t_datas *list, t_flist *head,
					t_main *main, t_flist *head2);
void			init_residus(t_glob_infos *tok_info);
void			init_tokens_bis(t_glob_infos *tok_info);
void			rules_bis(t_glob_infos *tok_info);
void			init_rules_bis(t_glob_infos *tok_info);
void			increment_i_k(int *i, int *k);
void			tok_creation(t_dblist *l, char *e, char *str);
void			is_cmd(t_datas *tag);
t_datas			*insert_lopp(t_datas *current, char *repere);
int				ft_strchrr(const char *s, int c);
void			ft_free_exit(t_main *main);
void			ft_free_hd(t_main *main);
void			ft_sigfork(void);
void			ft_launch_gcc(char *name);
void			ft_createprog(char *name);
void			ft_signal(int signum);
int				manage_sig_in_forks(pid_t pid, t_main *main);
char			*ft_trunc(char *name);
void			sig_quit_child(int sig);
int				manage_signal(void);
void			ft_sigquit(int sig);
void			ft_sigint(int sig);
void			fail_file(int file);
int				check_exitstatus(int exit_status, int i, int tothd,
					t_main *main);
void			cc_errors(char *cmd, t_exec_c *exec);
int				check_stat(char *command);
void			closing(t_main *main);
void			closing_bis(t_main *main);
void			get_origin_fd(t_main *main);
void			err_cmd_arg(t_main *main);
int				affiche(t_dblist *list);

#endif
