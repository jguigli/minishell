#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "structures.h"

//Structure globale partagee par tous les noeux
typedef	struct s_glob
{
	int		nb_pipes;
} t_glob;

//Structure pour cmd line sans pipe
typedef	struct s_datas
{
	char	*data;
	char	*type;
	struct s_datas 	*next;
	struct s_datas 	*previous;
	struct s_glob	*glob;	
} t_datas;

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

/*typedef struct s_tokens
{
	enum
	{
		TOKEN_HYPHEN,
		TOKEN_RR,
		TOKEN_LL,
		TOKEN_RD,
		TOKEN_PIPE,
		TOKEN_SLASH,
		TOKEN_BSLASH,
		TOKEN_DOLLAR,
		TOKEN_PARENR,
		TOKEN_PARENL,
		TOKEN_BACKETR,
		TOKEN_BRACKETL,
		TOKEN_DQUOTEL,
		TOKEN_DQUOTER,
		TOKEN_SQUOTEL,
		TOKEN_SQUOTER,
	} type;
	char *value;
	int  pos;
}	t_tokens;*/

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
	TOKEN_MAX
}					t_toktype;

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
	CHR_MAX
}					t_chr_class;


static t_chr_class		g_get_chr_class[255] =
{
	[' '] = CHR_SP,
	['\t'] = CHR_SP,
	[';'] = CHR_SEMI,
	['$'] = CHR_DOL,
	['#'] = CHR_WORD,
	['|'] = CHR_PIPE,
	['A'...'Z'] = CHR_WORD,
	['a'...'z'] = CHR_WORD,
	['0'...'9'] = CHR_DIGIT,

};

static t_toktype		g_get_tok_type[CHR_MAX] = {
	[CHR_SP] = TOKEN_SP,
	[CHR_PIPE] = TOKEN_PIPE,
	[CHR_WORD] = TOKEN_WORD,
	[CHR_ESCAPE] = TOKEN_WORD,
	[CHR_DASH] = TOKEN_WORD,
	[CHR_DIGIT] = TOKEN_WORD,
	[CHR_BANG] = TOKEN_BANG,
};

static int				g_token_chr_rules[TOKEN_MAX][CHR_MAX] =
{
	[TOKEN_SP] = {
		[CHR_SP] = 0
	},
	[TOKEN_WORD] = {
		[CHR_WORD] = 1,
		[CHR_DIGIT] = 1,
		[CHR_ESCAPE] = 1,
		[CHR_SQUOTE] = 1,
		[CHR_DQUOTE] = 1,
		[CHR_BQUOTE] = 1,
		[CHR_LPAREN] = 1,
		[CHR_RPAREN] = 0,
		[CHR_LBRACE] = 1,
		[CHR_RBRACE] = 0,
		[CHR_PIPE] = 1,
		[CHR_DOL] = 1,
		[CHR_DASH] = 1
	},
};

#endif