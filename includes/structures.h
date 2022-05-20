#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "minishell.h"

// on définit tokens selon grammaire shell
typedef enum		e_toktype {
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
	CHR_MAX
}					t_chr_class;


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

//struct pour BST
typedef	struct s_treenode
{
	t_datas		  *info;
	struct s_treenode *left;
	struct s_treenode *right;
} t_treenode;

//
typedef struct s_queue  
{  
    int 				front;
	int					rear; 
	int					size;  
    struct s_treenode	**arr;  
}	t_queue;







#endif