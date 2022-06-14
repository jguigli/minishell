#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "minishell.h"

// on définit tokens selon grammaire shell
typedef enum		e_toktype {
	TOKEN_ERROR, //0
	TOKEN_SP,//1
	TOKEN_BANG, //2
	TOKEN_AND, //3
	TOKEN_SEMI, //4
	TOKEN_WORD, //5
	TOKEN_RRED, //6
	TOKEN_LRED, //7
	TOKEN_ESCAPE, //8
	TOKEN_DIGIT, //9
	TOKEN_DOL, //10
	TOKEN_PIPE, //11
	TOKEN_SQUOTE, //12
	TOKEN_DQUOTE, //13
	TOKEN_BQUOTE, //14
	TOKEN_LPAREN, //15
	TOKEN_RPAREN, //16
	TOKEN_HYPHEN, //17
	TOKEN_LBRACE, //18
	TOKEN_RBRACE, //19
	TOKEN_WILDC, //20
	TOKEN_FILE, //21
	TOKEN_EQ, //22
	TOKEN_EOF, //23
	TOKEN_CMD, //24
	TOKEN_OPT, //25
	TOKEN_BS, //26
	TOKEN_SLASH, //27
	TOKEN_DOT, //28
	TOKEN_COMA, //29
	TOKEN_ESP, //30
	TOKEN_DASH, //31
	TOKEN_UNDS, //32
	TOKEN_HEREDOC, //33
	TOKEN_HEREDOC_DASH, //34=
	SIMPLE_DELIM, //35
	DQUOTED_DELIM,//36
	SQUOTED_DELIM,//37
	TOKEN_RRED_APPEND,//38
	TOKEN_HEREDOC_STRING,//39
	TOKEN_NL,//40
	TOKEN_QUERY,//41
	TOKEN_AROB,//42
	TOKEN_DIEZ,//43
	TOKEN_TILDE, //44
	TOKEN_MAX
}					t_toktype;

// on definit des enums pour reconnaitre chaque char et le categoriser
typedef enum		e_chr_class {
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
	CHR_MAX
}					t_chr_class;

typedef struct s_glob
{
	int		status;
	char	**env;
	int		my_fds[2];
	int		my_oldfds[2];
}	t_glob;


typedef	struct s_glob_infos
{
	t_chr_class	get_chr_c[255];
	t_toktype	get_tok_type[255];
	int		get_chr_rules[255][255];
	int		sp;
	int		nb_pipes;
}	t_glob_infos;

typedef	struct s_datas
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
	struct s_datas 	*next;
	struct s_datas 	*previous;
} t_datas;

// Jai rajoute quelques param pur identifier un noeud et ce quil contient
// - 1 : contient le cara
// - 0 : ne contient pas
// - length : correspond a la long du mot;

// Struct pour points d'entrée de la liste
typedef struct s_dblist
{
	int				number;
	t_datas 		*first;
	t_datas 		*last;
	t_glob_infos 	*infos;
} t_dblist;

typedef	struct s_flist
{
	int			number;
	t_dblist	*process;
	int			nb_rred;
	int			pos_rred;
	int			nb_rred_app;
	int			pos_rred_app;
	int			nb_lred;
	int			pos_lred;
	int			nb_heredoc;
	int			pos_heredoc;	
	int			nb_options;
	int			pos_options;	
	struct s_flist 	*next;
	struct s_flist 	*previous;
} t_flist;

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

#endif
