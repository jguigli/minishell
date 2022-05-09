#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "structures.h"

typedef	struct s_datas
{
	char			*data;
	unsigned int	type;
	char			*t_token;
	int				pos;
	struct s_datas 	*next;
	struct s_datas 	*previous;
	struct s_glob	*glob;	// utilité ?
} t_datas;

// Struct pour points d'entrée de la liste
typedef struct s_dblist
{
	int		number;
	int		has_pipe;
	int		has_redir;
	t_datas *first;
	t_datas *last;
} t_dblist;

// Struct arbre syntaxique abstrait
typedef struct s_ast
{
	t_datas *s_list;
	struct s_ast *parent;
	struct s_ast *right;
	struct s_ast *left;
} t_ast;

//Structure globale partagee par tous les noeux
typedef	struct s_glob
{
	int		nb_pipes;
	int		should_run;
	t_dblist	*list;
} t_glob;

//Structure pour cmd line ac pipe
typedef	struct s_blocks
{
	char	*block;
	char	**spl_bl;
	int		id;
	struct s_datas 	*ll_pipe;
	struct s_blocks 	*next;
	struct s_blocks 	*previous;
} t_blocks;

// Struct pur construire les built-in
typedef	struct s_myBuiltins
{
	char *name;
	int (*func)(void);	
} t_myBuiltins;

// on définit tokens selon grammaire shell
typedef enum		e_toktype {
	TOKEN_ERROR,
	TOKEN_SP,
	TOKEN_DASH,
	TOKEN_BANG,
	TOKEN_AND,
	TOKEN_SEMI,
	TOKEN_WORD,
	TOKEN_ESCAPE,
	TOKEN_DIGIT,
	TOKEN_DOL,
	TOKEN_PIPE,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_BQUOTE,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_WILDC,
	TOKEN_MAX
}					t_toktype;

// on definit des enums pour reconnaitre chaque char et le categoriser
typedef enum		e_chr_class {
	CHR_ERROR,
	CHR_SP,
	CHR_PIPE,
	CHR_DASH,
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
	CHR_LPAREN,
	CHR_RPAREN,
	CHR_LBRACE,
	CHR_RBRACE,
	CHR_WILDC,
	CHR_DIEZ,
	CHR_HYPHEN,
	CHR_MAX
}					t_chr_class;


// Total abstraction = representing only the essential details in the program. Ici on definit tous les enums pour abstraire les char qui nous interessent. Tableau de t_chr_class, prend en param, la valeur entre crochet pour donner l'index
static t_chr_class		g_get_chr_class[255] =
{
	[' '] = CHR_SP,
	['\t'] = CHR_SP,
	[';'] = CHR_SEMI,
	['$'] = CHR_DOL,
	['#'] = CHR_DIEZ,
	['|'] = CHR_PIPE,
	['-'] = CHR_HYPHEN,
	['('] = CHR_RPAREN,
	[')'] = CHR_LPAREN,
	['*'] = CHR_WILDC,
	[39] = CHR_SQUOTE,
	[34] = CHR_DQUOTE,
	['['] = CHR_LBRACE,
	[']'] = CHR_RBRACE,
	['!'] = CHR_BANG,
	['A'...'Z'] = CHR_WORD,
	['a'...'z'] = CHR_WORD,
	['0'...'9'] = CHR_DIGIT,

};

// tableau de t_toktype pour definir le token courant avant le de le processer à partir du premier carac
static t_toktype		g_get_tok_type[CHR_MAX] = {
//Ici lindex est CHR MAX pour prevoir large en terme dalloc despace mem. Comme CHR MAX EST LE DERNIER DE LA LISTE ENUM "t_chr_class" donc il aura la derniere position (ex : 30 ou 40)
	[CHR_SP] = TOKEN_SP,
	[CHR_AND] = TOKEN_AND,
	[CHR_PIPE] = TOKEN_PIPE,
	[CHR_WORD] = TOKEN_WORD,
	[CHR_ESCAPE] = TOKEN_WORD,
	[CHR_DIEZ] = TOKEN_WORD,
	[CHR_HYPHEN] = TOKEN_WORD,
	[CHR_DASH] = TOKEN_WORD,
	[CHR_DIGIT] = TOKEN_WORD,
	[CHR_BANG] = TOKEN_BANG,
	[CHR_SEMI] = TOKEN_SEMI,
	[CHR_DOL] = TOKEN_DOL,
	[CHR_WILDC] = TOKEN_WILDC,
	[CHR_DQUOTE] = TOKEN_DQUOTE,
	[CHR_SQUOTE] = TOKEN_SQUOTE,
	[CHR_LBRACE] = TOKEN_LBRACE,
	[CHR_RBRACE] = TOKEN_RBRACE,
	[CHR_LPAREN] = TOKEN_LPAREN,
	[CHR_RPAREN] = TOKEN_RPAREN,
	[CHR_BQUOTE] = TOKEN_BQUOTE,
};

static int				g_token_chr_rules[TOKEN_MAX][CHR_MAX] =
{
	[TOKEN_SP] = {
		[CHR_SP] = 0
	},
	[TOKEN_WORD] = {
		[CHR_WORD] = 1,
		[CHR_DIGIT] = 1,
		[CHR_SQUOTE] = 0,
		[CHR_DQUOTE] = 0,
		[CHR_BQUOTE] = 1,
		[CHR_LPAREN] = 1,
		[CHR_RPAREN] = 0,
		[CHR_LBRACE] = 1,
		[CHR_RBRACE] = 0,
		//[CHR_PIPE] = 1,
		[CHR_DOL] = 1,
		[CHR_DASH] = 1,
	},
	[TOKEN_PIPE] = {
		[CHR_PIPE] = 1,
		[CHR_WORD] = 0,
		[CHR_SP] = 0,
	},
	[TOKEN_DQUOTE] = {
		[CHR_WORD] = 1,
		[CHR_DQUOTE] = 0
	},
	[TOKEN_SQUOTE] = {
		[CHR_WORD] = 1,
		[CHR_SQUOTE] = 0
	},
};

#endif