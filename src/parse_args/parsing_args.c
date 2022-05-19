#include "../../includes/minishell.h"

void	init_classes(t_glob_infos *tok_info)
{
	tok_info->get_chr_c[255];

	tok_info->get_chr_c[' '] = CHR_SP;
	tok_info->get_chr_c['\t'] = CHR_SP;
	tok_info->get_chr_c[';'] = CHR_SEMI;
	tok_info->get_chr_c['$'] = CHR_WORD;
	tok_info->get_chr_c['#'] = CHR_DIEZ;
	tok_info->get_chr_c['|'] = CHR_PIPE;
	tok_info->get_chr_c['-'] = CHR_WORD;
	tok_info->get_chr_c['>'] = CHR_RRED;
	tok_info->get_chr_c['<'] = CHR_LRED;
	tok_info->get_chr_c['\"'] = CHR_DQUOTE;
	tok_info->get_chr_c['\''] = CHR_SQUOTE;
	tok_info->get_chr_c['('] = CHR_WORD;
	tok_info->get_chr_c[')'] = CHR_WORD;
	tok_info->get_chr_c['*'] = CHR_WILDC;
	tok_info->get_chr_c['['] = CHR_LBRACE;
	tok_info->get_chr_c[']'] = CHR_RBRACE;
	tok_info->get_chr_c['{'] = CHR_WORD;
	tok_info->get_chr_c['}'] = CHR_WORD;
	tok_info->get_chr_c['!'] = CHR_BANG;
	tok_info->get_chr_c['a'] = CHR_WORD;
	tok_info->get_chr_c['b'] = CHR_WORD;
	tok_info->get_chr_c['c'] = CHR_WORD;
	tok_info->get_chr_c['d'] = CHR_WORD;
	tok_info->get_chr_c['e'] = CHR_WORD;
	tok_info->get_chr_c['f'] = CHR_WORD;
	tok_info->get_chr_c['g'] = CHR_WORD;
	tok_info->get_chr_c['h'] = CHR_WORD;
	tok_info->get_chr_c['i'] = CHR_WORD;
	tok_info->get_chr_c['j'] = CHR_WORD;
	tok_info->get_chr_c['k'] = CHR_WORD;
	tok_info->get_chr_c['l'] = CHR_WORD;
	tok_info->get_chr_c['m'] = CHR_WORD;
	tok_info->get_chr_c['n'] = CHR_WORD;
	tok_info->get_chr_c['o'] = CHR_WORD;
	tok_info->get_chr_c['p'] = CHR_WORD;
	tok_info->get_chr_c['q'] = CHR_WORD;
	tok_info->get_chr_c['r'] = CHR_WORD;
	tok_info->get_chr_c['s'] = CHR_WORD;
	tok_info->get_chr_c['t'] = CHR_WORD;
	tok_info->get_chr_c['u'] = CHR_WORD;
	tok_info->get_chr_c['v'] = CHR_WORD;
	tok_info->get_chr_c['w'] = CHR_WORD;
	tok_info->get_chr_c['x'] = CHR_WORD;
	tok_info->get_chr_c['y'] = CHR_WORD;
	tok_info->get_chr_c['z'] = CHR_WORD;
	tok_info->get_chr_c['A'] = CHR_WORD;
	tok_info->get_chr_c['B'] = CHR_WORD;
	tok_info->get_chr_c['C'] = CHR_WORD;
	tok_info->get_chr_c['D'] = CHR_WORD;
	tok_info->get_chr_c['E'] = CHR_WORD;
	tok_info->get_chr_c['F'] = CHR_WORD;
	tok_info->get_chr_c['G'] = CHR_WORD;
	tok_info->get_chr_c['H'] = CHR_WORD;
	tok_info->get_chr_c['I'] = CHR_WORD;
	tok_info->get_chr_c['J'] = CHR_WORD;
	tok_info->get_chr_c['K'] = CHR_WORD;
	tok_info->get_chr_c['L'] = CHR_WORD;
	tok_info->get_chr_c['M'] = CHR_WORD;
	tok_info->get_chr_c['N'] = CHR_WORD;
	tok_info->get_chr_c['O'] = CHR_WORD;
	tok_info->get_chr_c['P'] = CHR_WORD;
	tok_info->get_chr_c['Q'] = CHR_WORD;
	tok_info->get_chr_c['R'] = CHR_WORD;
	tok_info->get_chr_c['S'] = CHR_WORD;
	tok_info->get_chr_c['T'] = CHR_WORD;
	tok_info->get_chr_c['U'] = CHR_WORD;
	tok_info->get_chr_c['V'] = CHR_WORD;
	tok_info->get_chr_c['W'] = CHR_WORD;
	tok_info->get_chr_c['X'] = CHR_WORD;
	tok_info->get_chr_c['Y'] = CHR_WORD;
	tok_info->get_chr_c['Z'] = CHR_WORD;
	tok_info->get_chr_c['0'] = CHR_DIGIT;
	tok_info->get_chr_c['0'] = CHR_DIGIT;
	tok_info->get_chr_c['1'] = CHR_DIGIT;
	tok_info->get_chr_c['2'] = CHR_DIGIT;
	tok_info->get_chr_c['3'] = CHR_DIGIT;
	tok_info->get_chr_c['4'] = CHR_DIGIT;
	tok_info->get_chr_c['5'] = CHR_DIGIT;
	tok_info->get_chr_c['6'] = CHR_DIGIT;
	tok_info->get_chr_c['7'] = CHR_DIGIT;
	tok_info->get_chr_c['8'] = CHR_DIGIT;
	tok_info->get_chr_c['9'] = CHR_DIGIT;
	tok_info->get_chr_c['='] = CHR_EQ;
	tok_info->get_chr_c['\0'] = CHR_EOF;
	tok_info->get_chr_c['\\'] = CHR_WORD;
	tok_info->get_chr_c['/'] = CHR_WORD;
	tok_info->get_chr_c['.'] = CHR_WORD;
}

void	init_tokens(t_glob_infos *tok_info)
{
	tok_info->get_tok_type[255];

	tok_info->get_tok_type[CHR_SP] = TOKEN_SP;
	tok_info->get_tok_type[CHR_AND] = TOKEN_AND;
	tok_info->get_tok_type[CHR_PIPE] = TOKEN_PIPE;
	tok_info->get_tok_type[CHR_WORD] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_ESCAPE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_DIEZ] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_RRED] = TOKEN_RRED;
	tok_info->get_tok_type[CHR_LRED] = TOKEN_LRED;
	tok_info->get_tok_type[CHR_DIGIT] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_BANG] = TOKEN_BANG;
	tok_info->get_tok_type[CHR_SEMI] = TOKEN_SEMI;
	tok_info->get_tok_type[CHR_DOL] = TOKEN_DOL;
	tok_info->get_tok_type[CHR_WILDC] = TOKEN_WILDC;
	tok_info->get_tok_type[CHR_DQUOTE] = TOKEN_DQUOTE;
	tok_info->get_tok_type[CHR_SQUOTE] = TOKEN_SQUOTE;
	tok_info->get_tok_type[CHR_LBRACE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_RBRACE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_LPAREN] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_RPAREN] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_BQUOTE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_EQ] = TOKEN_EQ;
	tok_info->get_tok_type[CHR_EOF] = TOKEN_EOF;
}

void	init_rules(t_glob_infos *tok_info)
{
	tok_info->get_chr_rules[TOKEN_MAX][CHR_MAX];

	tok_info->get_chr_rules[TOKEN_SP][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_WORD] = 0;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DIGIT] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_SQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_BQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_LPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_LBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DIGIT] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_SQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_BQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_RPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_RBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_BQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_SP] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_SP] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_EOF] = 0;
}

t_glob_infos	*initst_infos()
{
	t_glob_infos	*tok_info;

	tok_info = malloc(sizeof(t_glob_infos));
	if (!tok_info)
		return (NULL);
	init_classes(tok_info);
	init_tokens(tok_info);
	init_rules(tok_info);
	return (tok_info);
}


void	parse_args(char	*entry, char **env)
{
	t_dblist		*fin_li;

	fin_li = get_tokens(entry);
	shell_parameter_expansion(fin_li, env);

}