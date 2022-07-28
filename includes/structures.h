/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:25:57 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:25:59 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "minishell.h"

typedef enum e_toktype {
	TOKEN_ERROR,
	TOKEN_SP,
	TOKEN_BANG,
	TOKEN_AND,
	TOKEN_SEMI,
	TOKEN_WORD,
	TOKEN_RRED,
	TOKEN_LRED,
	TOKEN_ESCAPE,
	TOKEN_DIGIT,
	TOKEN_DOL,
	TOKEN_PIPE,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_BQUOTE,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_HYPHEN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_WILDC,
	TOKEN_FILE,
	TOKEN_EQ,
	TOKEN_EOF,
	TOKEN_CMD,
	TOKEN_OPT,
	TOKEN_BS,
	TOKEN_SLASH,
	TOKEN_DOT,
	TOKEN_COMA,
	TOKEN_ESP,
	TOKEN_DASH,
	TOKEN_UNDS,
	TOKEN_HEREDOC,
	TOKEN_HEREDOC_DASH,
	SIMPLE_DELIM,
	DQUOTED_DELIM,
	SQUOTED_DELIM,
	TOKEN_RRED_APPEND,
	TOKEN_HEREDOC_STRING,
	TOKEN_NL,
	TOKEN_QUERY,
	TOKEN_AROB,
	TOKEN_DIEZ,
	TOKEN_TILDE,
	TOKEN_COLON,
	TOKEN_PERCENT,
	TOKEN_CIRC,
	TOKEN_PLUS,
	TOKEN_UACC,
	TOKEN_BT,
	TOKEN_LEMBRACE,
	TOKEN_REMBRACE,
	TOKEN_AST,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_DEL,
	TOKEN_MAX
}					t_toktype;

typedef enum e_chr_class {
	CHR_ERROR,
	CHR_SP,
	CHR_PIPE,
	CHR_BANG,
	CHR_AND,
	CHR_SEMI,
	CHR_WORD,
	CHR_ESCAPE,
	CHR_DIGIT,
	CHR_DOL,
	CHR_SQUOTE,
	CHR_DQUOTE,
	CHR_BQUOTE,
	CHR_RRED,
	CHR_LRED,
	CHR_LPAREN,
	CHR_RPAREN,
	CHR_LBRACE,
	CHR_RBRACE,
	CHR_LBRACKET,
	CHR_RBRACKET,
	CHR_WILDC,
	CHR_DIEZ,
	CHR_EQ,
	CHR_EOF,
	CHR_BS,
	CHR_SLASH,
	CHR_DOT,
	CHR_COMA,
	CHR_ESP,
	CHR_DASH,
	CHR_UNDS,
	CHR_NL,
	CHR_QUERY,
	CHR_AROB,
	CHR_TILDE,
	CHR_COLON,
	CHR_PERCENT,
	CHR_CIRC,
	CHR_PLUS,
	CHR_UACC,
	CHR_BT,
	CHR_LEMBRACE,
	CHR_REMBRACE,
	CHR_AST,
	CHR_MAX
}					t_chr_class;

typedef struct s_glob_infos
{
	t_chr_class	gch[255];
	t_toktype	gtt[255];
	int			grul[255][255];
	char		*types[1024];
	int			nb_pipes;
	int			ctrls;
	int			k;
	int			m;
	char		*st;
	int			dq;
	int			sq;
	int			tt;
	int			sp;
	int			pos;
	int			incr;
	int			check;
}	t_glob_infos;

typedef struct s_datas
{
	char			*data;
	unsigned int	type;
	char			*t_token;
	int				level;
	int				pos;
	int				space;
	int				dq;
	int				dol;
	int				redir;
	int				sq;
	int				sp_char;
	int				length;
	int				expansion;
	struct s_datas	*next;
	struct s_datas	*previous;
}	t_datas;

typedef struct s_dblist
{
	int				number;
	t_datas			*first;
	t_datas			*last;
	t_glob_infos	*in;
}	t_dblist;

typedef struct s_flist
{
	int				number;
	t_dblist		*process;
	int				nb_rred;
	int				pos_rred;
	int				nb_rred_app;
	int				pos_rred_app;
	int				nb_lred;
	int				pos_lred;
	int				nb_heredoc;
	int				pos_heredoc;	
	int				nb_options;
	int				pos_options;	
	struct s_flist	*next;
	struct s_flist	*previous;
}	t_flist;

typedef struct s_exec_c
{
	pid_t	*pid;
	int		*pipe;
	char	*path;
	char	**cmd_path;
	char	**cmd_arg;
	char	*cmd;
	int		pipe_number;
	int		cmd_number;
	int		pid_number;
}	t_exec_c;

typedef struct s_exec_s
{
	pid_t	pid;
	char	*path;
	char	**cmd_path;
	char	**cmd_arg;
	char	*cmd;
	int		pipe_number;
	int		cmd_number;
}	t_exec_s;

typedef struct s_main
{
	t_flist		*start;
	t_exec_c	*exec_c;
	t_exec_s	*exec_s;
	char		**env;
	char		**export;
	char		*my_prompt;
	int			my_fds[2];
	int			my_oldfds[2];
	int			sigintos;
	char		*node_toadd;
	char		*tmp;
	int			file;
	int			i;
	pid_t		fi;
	pid_t		pid;
	int			k;
	int			hd_wstatus;
	int			exec_wstatus;
	int			ret;
	int			tota_heredoc;
}	t_main;

#endif
