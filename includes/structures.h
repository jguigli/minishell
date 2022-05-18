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
	TOKEN_EQ,
	TOKEN_EOF,
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
	CHR_MAX
}					t_chr_class;


// Total abstraction = representing only the essential details in the program. Ici on definit tous les enums pour abstraire les char qui nous interessent. Tableau de t_chr_class, prend en param, la valeur entre crochet pour donner l'index
// static t_chr_class		g_get_chr_class[255] =
// {
// 	[' '] = CHR_SP,
// 	['\t'] = CHR_SP,
// 	[';'] = CHR_SEMI,
// 	['$'] = CHR_WORD,
// 	['#'] = CHR_DIEZ,
// 	['|'] = CHR_PIPE,
// 	['-'] = CHR_WORD,
// 	['>'] = CHR_RRED,
// 	['<'] = CHR_LRED,
// 	['\"'] = CHR_WORD,
// 	['\''] = CHR_WORD,
// 	['('] = CHR_WORD,
// 	[')'] = CHR_WORD,
// 	['*'] = CHR_WILDC,
// 	['['] = CHR_LBRACE,
// 	[']'] = CHR_RBRACE,
// 	['!'] = CHR_BANG,
// 	['A'...'Z'] = CHR_WORD,
// 	['a'...'z'] = CHR_WORD,
// 	['0'...'9'] = CHR_DIGIT,
// 	['='] = CHR_EQ,
// };

// tableau de t_toktype pour definir le token courant avant le de le processer à partir du premier carac
// static t_toktype		g_get_tok_type[CHR_MAX] = {
// //Ici lindex est CHR MAX pour prevoir large en terme dalloc despace mem. Comme CHR MAX EST LE DERNIER DE LA LISTE ENUM "t_chr_class" donc il aura la derniere position (ex : 30 ou 40)
// 	[CHR_SP] = TOKEN_SP,
// 	[CHR_AND] = TOKEN_AND,
// 	[CHR_PIPE] = TOKEN_PIPE,
// 	[CHR_WORD] = TOKEN_WORD,
// 	[CHR_ESCAPE] = TOKEN_WORD,
// 	[CHR_DIEZ] = TOKEN_WORD,
// 	[CHR_RRED] = TOKEN_RRED,
// 	[CHR_LRED] = TOKEN_LRED,
// 	[CHR_DIGIT] = TOKEN_WORD,
// 	[CHR_BANG] = TOKEN_BANG,
// 	[CHR_SEMI] = TOKEN_SEMI,
// 	[CHR_DOL] = TOKEN_DOL,
// 	[CHR_WILDC] = TOKEN_WILDC,
// 	[CHR_DQUOTE] = TOKEN_WORD,
// 	[CHR_SQUOTE] = TOKEN_WORD,
// 	[CHR_LBRACE] = TOKEN_WORD,
// 	[CHR_RBRACE] = TOKEN_WORD,
// 	[CHR_LPAREN] = TOKEN_WORD,
// 	[CHR_RPAREN] = TOKEN_WORD,
// 	[CHR_BQUOTE] = TOKEN_WORD,
// 	[CHR_EQ] = TOKEN_EQ,
// };

// static int				g_token_chr_rules[TOKEN_MAX][CHR_MAX] =
// {
// 	[TOKEN_SP] = {
// 		[CHR_SP] = 0
// 	},
// 	[TOKEN_EQ] = {
// 		[CHR_EQ] = 1,
// 		[CHR_DIGIT] = 0,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 0,
// 		[CHR_LPAREN] = 0,
// 		[CHR_RPAREN] = 0,
// 		[CHR_LBRACE] = 0,
// 		[CHR_RBRACE] = 0,
// 		[CHR_DOL] = 0,
// 		[CHR_SP] = 0
// 	},
// 	[TOKEN_ESCAPE] = {
// 		[CHR_ESCAPE] = 0
// 	},
// 	[TOKEN_WORD] = {
// 		[CHR_WORD] = 1,
// 		[CHR_DIGIT] = 1,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 1,
// 		[CHR_LPAREN] = 1,
// 		[CHR_RPAREN] = 0,
// 		[CHR_LBRACE] = 1,
// 		[CHR_RBRACE] = 0,
// 		[CHR_DOL] = 1,
// 		[CHR_SP] = 0
// 	},
// 	[TOKEN_PIPE] = {
// 		[CHR_PIPE] = 1,
// 		[CHR_WORD] = 0,
// 		[CHR_SP] = 0,
// 	},
// 	[TOKEN_RRED] = {
// 		[CHR_RRED] = 1,
// 		[CHR_WORD] = 0,
// 		[CHR_DIGIT] = 0,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 0,
// 		[CHR_LPAREN] = 0,
// 		[CHR_RPAREN] = 0,
// 		[CHR_LBRACE] = 0,
// 		[CHR_RBRACE] = 0,
// 		[CHR_DOL] = 0,
// 		[CHR_SP] = 0,
// 	},
// 	[TOKEN_LRED] = {
// 		[CHR_LRED] = 1,
// 		[CHR_WORD] = 0,
// 		[CHR_DIGIT] = 0,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 0,
// 		[CHR_LPAREN] = 0,
// 		[CHR_RPAREN] = 0,
// 		[CHR_LBRACE] = 0,
// 		[CHR_RBRACE] = 0,
// 		[CHR_DOL] = 0,
// 		[CHR_SP] = 0,
// 	},
// 	[TOKEN_DOL] = {
// 		[CHR_DOL] = 1,
// 		[CHR_LRED] = 0,
// 		[CHR_WORD] = 1,
// 		[CHR_DIGIT] = 1,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 0,
// 		[CHR_LPAREN] = 1,
// 		[CHR_RPAREN] = 1,
// 		[CHR_LBRACE] = 0,
// 		[CHR_RBRACE] = 0,
// 	},
// 	[TOKEN_WILDC] = {
// 		[CHR_WILDC] = 1,
// 		[CHR_LRED] = 0,
// 		[CHR_WORD] = 1,
// 		[CHR_DIGIT] = 1,
// 		[CHR_SQUOTE] = 0,
// 		[CHR_DQUOTE] = 0,
// 		[CHR_BQUOTE] = 0,
// 		[CHR_LPAREN] = 0,
// 		[CHR_RPAREN] = 0,
// 		[CHR_LBRACE] = 0,
// 		[CHR_RBRACE] = 0,
// 	},
// 	[TOKEN_DQUOTE] = {
// 		[CHR_DQUOTE] = 1,
// 		[CHR_SP] = 1,
// 		[CHR_AND] = 1,
// 		[CHR_PIPE] = 1,
// 		[CHR_SQUOTE] = 1,
// 		[CHR_WORD] = 1,
// 		[CHR_ESCAPE] = 1,
// 		[CHR_DIEZ] = 1,
// 		[CHR_RRED] = 1,
// 		[CHR_LRED] = 1,
// 		[CHR_DIGIT] = 1,
// 		[CHR_BANG] = 1,
// 		[CHR_SEMI] = 1,
// 		[CHR_DOL] = 1,
// 		[CHR_WILDC] = 1,
// 		[CHR_LBRACE] = 1,
// 		[CHR_RBRACE] = 1,
// 		[CHR_LPAREN] = 1,
// 		[CHR_RPAREN] = 1,
// 		[CHR_BQUOTE] = 1,
// 	},
// 	[TOKEN_SQUOTE] = {
// 		[CHR_SP] = 1,
// 		[CHR_AND] = 1,
// 		[CHR_PIPE] = 1,
// 		[CHR_WORD] = 1,
// 		[CHR_ESCAPE] = 1,
// 		[CHR_DIEZ] = 1,
// 		[CHR_RRED] = 1,
// 		[CHR_LRED] = 1,
// 		[CHR_DIGIT] = 1,
// 		[CHR_BANG] = 1,
// 		[CHR_SEMI] = 1,
// 		[CHR_DOL] = 1,
// 		[CHR_WILDC] = 1,
// 		[CHR_DQUOTE] = 1,
// 		[CHR_SQUOTE] = 1,
// 		[CHR_LBRACE] = 1,
// 		[CHR_RBRACE] = 1,
// 		[CHR_LPAREN] = 1,
// 		[CHR_RPAREN] = 1,
// 		[CHR_BQUOTE] = 1,
// 	},
// };

typedef	struct s_glob_infos
{
	t_chr_class	get_chr_c[255];
	t_toktype	get_tok_type[255];
	int		get_chr_rules[255][255];
	int		sp;
}	t_glob_infos;

typedef	struct s_datas
{
	char			*data;
	unsigned int	type;
	char			*t_token;
	int				level;
	int				pos;
	int				space;
	struct s_datas 	*next;
	struct s_datas 	*previous;
} t_datas;

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