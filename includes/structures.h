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