#include "../../includes/minishell.h"

void	init_classes(t_glob_infos *tok_info)
{
	//tok_info->get_chr_c[255];
	tok_info->get_chr_c[' '] = CHR_SP;
	tok_info->get_chr_c['\t'] = CHR_SP;
	tok_info->get_chr_c[';'] = CHR_SEMI;
	tok_info->get_chr_c[','] = CHR_COMA;
	tok_info->get_chr_c['$'] = CHR_DOL;
	tok_info->get_chr_c['#'] = CHR_DIEZ;
	tok_info->get_chr_c['@'] = CHR_AROB;
	tok_info->get_chr_c['|'] = CHR_PIPE;
	tok_info->get_chr_c['-'] = CHR_DASH;
	tok_info->get_chr_c['_'] = CHR_UNDS;
	tok_info->get_chr_c['>'] = CHR_RRED;
	tok_info->get_chr_c['<'] = CHR_LRED;
	tok_info->get_chr_c['\"'] = CHR_DQUOTE;
	tok_info->get_chr_c['\''] = CHR_SQUOTE;
	tok_info->get_chr_c['&'] = CHR_ESP;
	tok_info->get_chr_c['~'] = CHR_TILDE;
	tok_info->get_chr_c['('] = CHR_RPAREN;
	tok_info->get_chr_c[')'] = CHR_LPAREN;
	tok_info->get_chr_c['*'] = CHR_WILDC;
	tok_info->get_chr_c['['] = CHR_LBRACE;
	tok_info->get_chr_c[']'] = CHR_RBRACE;
	tok_info->get_chr_c['{'] = CHR_WORD;
	tok_info->get_chr_c['}'] = CHR_WORD;
	tok_info->get_chr_c['!'] = CHR_BANG;
	tok_info->get_chr_c['?'] = CHR_QUERY;
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
	tok_info->get_chr_c['\n'] = CHR_NL;
	tok_info->get_chr_c['\\'] = CHR_BS;
	tok_info->get_chr_c['/'] = CHR_SLASH;
	tok_info->get_chr_c['.'] = CHR_DOT;
	tok_info->get_chr_c[':'] = CHR_COLON;
}

void	init_tokens(t_glob_infos *tok_info)
{
	//tok_info->get_tok_type[255];
	tok_info->get_tok_type[CHR_SP] = TOKEN_SP;
	tok_info->get_tok_type[CHR_AND] = TOKEN_AND;
	tok_info->get_tok_type[CHR_PIPE] = TOKEN_PIPE;
	tok_info->get_tok_type[CHR_WORD] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_ESCAPE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_DIEZ] = TOKEN_DIEZ;
	tok_info->get_tok_type[CHR_RRED] = TOKEN_RRED;
	tok_info->get_tok_type[CHR_LRED] = TOKEN_LRED;
	tok_info->get_tok_type[CHR_LPAREN] = TOKEN_LPAREN;
	tok_info->get_tok_type[CHR_RPAREN] = TOKEN_RPAREN;	
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
	tok_info->get_tok_type[CHR_SLASH] = TOKEN_SLASH;
	tok_info->get_tok_type[CHR_DOT] = TOKEN_DOT;
	tok_info->get_tok_type[CHR_COMA] = TOKEN_COMA;
	tok_info->get_tok_type[CHR_DASH] = TOKEN_DASH;	
	tok_info->get_tok_type[CHR_ESP] = TOKEN_ESP;
	tok_info->get_tok_type[CHR_BS] = TOKEN_BS;
	tok_info->get_tok_type[CHR_UNDS] = TOKEN_UNDS;
	tok_info->get_tok_type[CHR_NL] = TOKEN_NL;
	tok_info->get_tok_type[CHR_QUERY] = TOKEN_QUERY;
	tok_info->get_tok_type[CHR_AROB] = TOKEN_AROB;
	tok_info->get_tok_type[CHR_TILDE] = TOKEN_TILDE;
	tok_info->get_tok_type[CHR_COLON] = TOKEN_COLON;
}

void	init_rules(t_glob_infos *tok_info)
{
	//tok_info->get_chr_rules[TOKEN_MAX][CHR_MAX];
	tok_info->get_chr_rules[TOKEN_SP][CHR_SP] = 1;
	tok_info->get_chr_rules[TOKEN_SP][CHR_DIGIT] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_SQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_DQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_BQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_LPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_RPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_LBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_RBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_COMA] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_DOL] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_SEMI] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_BANG] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_BS] = 0;	
	tok_info->get_chr_rules[TOKEN_SP][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_DOT] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_SLASH] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_ESP] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_DASH] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_RRED] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_LRED] = 0;
	tok_info->get_chr_rules[TOKEN_SP][CHR_EQ] = 0;
	tok_info->get_chr_rules[TOKEN_NL][CHR_NL] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_SEMI] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SEMI] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_BANG] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_BS] = 1;	
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_SLASH] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_AROB] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_WORD][CHR_EQ] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_PIPE][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DIGIT] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_WORD] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_SQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_LPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_LBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_RBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_ESP] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DOT] = 0;
	tok_info->get_chr_rules[TOKEN_RRED][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DIGIT] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_WORD] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_COMA] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_SQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_BQUOTE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_RPAREN] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_LBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_RBRACE] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_ESP] = 0;	
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DOT] = 0;
	tok_info->get_chr_rules[TOKEN_LRED][CHR_DASH] = 1;
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
	tok_info->get_chr_rules[TOKEN_DOL][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_COLON] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_EQ] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_ESP] = 1;	
	tok_info->get_chr_rules[TOKEN_DOL][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_DOL][CHR_QUERY] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_BS] = 1;	
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_EQ] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_COLON] = 1;	
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_SLASH] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_ESP] = 1;	
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_DQUOTE][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_SQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_LRED] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_RRED] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_EQ] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_COLON] = 1;	
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_BS] = 1;	
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_SLASH] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_SQUOTE][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_SLASH] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_BS] = 1;	
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SLASH][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_BS][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_BS][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_BS][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_BS][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_BS][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_SP] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_ESP][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_SEMI] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_SP] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_SEMI][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_COMA] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_COMA] = 1;	
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_COMA][CHR_DASH] = 1;	
	tok_info->get_chr_rules[TOKEN_DOT][CHR_DOT] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_DOT][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_DOT][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DASH] = 1;	
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_DASH][CHR_DASH] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_DASH][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_UNDS] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_UNDS][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_AROB] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_AROB][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_AROB][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_DIEZ] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_DIEZ][CHR_BS] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_TILDE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_DIGIT] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_WORD] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_DQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_BQUOTE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_LPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_RPAREN] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_LBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_RBRACE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_DOL] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_PIPE] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_SP] = 0;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_EOF] = 0;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_SLASH] = 1;	
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_ESP] = 1;
	tok_info->get_chr_rules[TOKEN_TILDE][CHR_BS] = 1;

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

int	my_lstsize(t_flist **lst)
{
	int		i;
	t_flist	*lstnext;

	lstnext = *lst;
	i = 0;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	//printf("%d \n", i);
	return (i);
}

int	my_lstsize_dblist(t_dblist *lst)
{
	int		i;
	t_datas	*lstnext;

	lstnext = lst->first;
	i = 0;
	while (lstnext)
	{
		lstnext = lstnext->next;
		i++;
	}
	return (i);
}

void counting(t_flist **gr_list)
{
	t_datas	*list;
	t_flist	*head;
	int	pos;

	head = *gr_list;
	pos = 1;
	//affiche(head->process);
	while(head)
	{
		list = head->process->first;
		//printf("list data ==> %s\n", head->process->first->data);
		while(list)
		{
			if	(list->type == 6)
			{
				head->nb_rred++;
				head->pos_rred = pos;
			}
			if	(list->type == 7)
			{
				head->nb_lred++ ;
				head->pos_lred = pos;
			}
			if	(list->type == 33)
			{
				head->nb_heredoc++;
				head->pos_heredoc = pos;
			}
			if	(list->type == 38)
			{
				head->pos_rred_app = pos;
				head->nb_rred_app++;
			}
			if	(list->type == 25)
			{
				head->nb_options++;
				head->pos_options = pos;;
			}
			pos++;
			if (list->next != NULL)
				list = 	list->next;
			else 
				break ;
		}
		pos = 0;
		if (head->next != NULL )
			head = head->next;
		else
			break ;
	}
	//printf("Nb heredoc depuis counting %d\n", head->nb_heredoc);
}

t_datas	*my_lstnew(char *data)
{
	t_datas	*newlist;

	newlist = ft_calloc(1, sizeof(t_datas));
	if (!newlist)
		return (NULL);
	newlist->data = data;
	return (newlist);
}

void	insert_node(char *repere, char *node_toadd, t_flist **head)
{
	t_datas	*tmp_tonext;
	t_datas	*current;
	t_datas	*new;
	t_flist	*copy_head;

	current = (*head)->process->first;
	copy_head = *head;
	//printf("repere%s  \n", repere);
	// printf("repere%s  \n", repere);
	// printf("ft strlen de repere %zu  \n", ft_strlen(repere));
	while (current && (ft_strcmp(current->data, repere)))
	{

		//printf("current data %s  --- ft srlen : %zu\n", current->data, ft_strlen(current->data));
		if (current->next)
			current = current->next;
		else
			break ;
	}
	//printf("current data%s  \n", current->data);
	if (current->next)
	{
		//printf("apres lol %s\n", current->next->data);
		tmp_tonext = current->next;
		new = my_lstnew(node_toadd);
		new->previous = current;
		current->next = new;
		new->pos = current->pos++;
		new->next = tmp_tonext;
		tmp_tonext->previous = new;
		copy_head->process->number ++;
		new->type = 39;
		new->t_token = "TOKEN_HEREDOC_STRING";
	}
	else
	{
		new = my_lstnew(node_toadd);
		new->previous = current;
		//printf("test %s  \n", new->previous->data);
		current->next = new;
		//printf("test %s  \n", current->next->data);
		new->next = NULL;
		copy_head->process->last = new;
		copy_head->process->number++;
		new->type = 39;
		new->pos = current->pos++;
		new->t_token = "TOKEN_HEREDOC_STRING";	
	}
	// exit(127);
}

int	waiting_child_hd(pid_t fi)
{
	int	wstatus;
	int	ret;

	ret = 0;
	//kill(fi, SIGINT);
	//sleep(60);
	wstatus = 0;
	if	(waitpid(fi, &wstatus, 0) == -1)
			perror("wait() error");
	//printf("wstatus == %d\n", wstatus);
	if (WIFSIGNALED(wstatus) > 0)
	{
		//printf("hehe\n");
		ret = (WTERMSIG(wstatus) + 128);
	}
	if (WIFEXITED(wstatus) > 0)
	{
		//printf("testouille -- %d\n", wstatus);
		ret = (WEXITSTATUS(wstatus));
	}
	if (WIFSTOPPED(wstatus))
	{
		//printf("hoho\n");
		ret = (WSTOPSIG(wstatus) + 128);
	}
	if (ret == 130)
		g.status = 130;
	return (ret);
}

int	simple_block_p(t_flist **gr_list)
{
	t_datas	*list;
	t_datas	*list2;
	t_flist	*head;
	int		i;
	int		j;
	pid_t		fi;
	char	*node_toadd;
	char	*tmp;
	int		file;

	list = (*gr_list)->process->first;
	list2 = (*gr_list)->process->first;
	head = *gr_list;
	//affiche(head->process);
	i = 0;
	j = 0;
	node_toadd = NULL;
	tmp = NULL;
	//printf("nb of heredoc %d\n", head->nb_heredoc);
	if	(head->nb_heredoc >= 1)
	{
		while (list && list->type != 33)
		{
			if (list->next)	
				list = list->next;
			else 
				break ;
		}
		//printf("there %s -- nb_hd = %d\n", list->data, head->nb_heredoc);
		while (i < head->nb_heredoc && list)
		{
			fi = fork();
			//printf("%d \n", fi);
			if	(fi < 0)
			{
				// freee tous les mallocs
				error_msgs(errno, "Fork failed");
				return (-200);
			}
			ft_sig_fork(fi);
			if (fi == 0)
			{
				//printf("list data %s \n", list->next->data);
				manage_one_redir(list->next, head);
				//if	(g.sigintos == 2)
				exit(1);
				//printf("prout\n");
				//return (1); // a essayer
			}
			else
			{
				waiting_child_hd(fi);
				// if (g.status == 130)
				// 	break ;
				//manage_signal();
				file = open(".hd1", O_RDONLY);
				if	(file < 0)
				{
					error_msgs(errno, ".hd1");
					return (-200);
				}
				tmp = get_next_line(file);
				//printf("tmp ==> %s\n", tmp);
				while (tmp != NULL)
				{
					node_toadd = ft_strjoin(node_toadd, tmp);
					//printf("node to add %s\n", node_toadd);
					free(tmp);
					tmp = get_next_line(file);		
				}
				close(file);
				if (list->next)
					list = list->next;
				else
					break ;
				//printf("list datataa == %s\n", list->data);
				insert_node(list->data, node_toadd, &head);
				node_toadd = NULL;
				tmp = NULL;
				while(list && list->type != 33)
				{
					if (list->next)
						list = list->next;
					else
						break ;
				}
				i ++;
			}
		}
	}
	return (0);
}

int	multiple_block_p(t_flist **gr_list, int totalhd)
{
	t_datas	*list;
	// t_datas	*list2;
	t_flist	*head;
	int		i;
	int		j;
	int		k;
	int		fi;
	char	*node_toadd;
	char	*tmp;
	int		file;

	// list = (*gr_list)->process->first;
	// list2 = (*gr_list)->process->first;
	head = *gr_list;
	i = 0;
	j = 0;
	k = 0;
	node_toadd = NULL;
	tmp = NULL;
	// printf("there %s\n", head->process->first->data);
	// printf("boucle 1 %s -- nb_heredoc : %d\n", head->process->first->data, head->nb_heredoc);
	while(head->nb_heredoc == 0)
	{
		if	(head->next)
			head = head->next;
		else
			break ;
	}
	//printf("Fin boucle 1 %s -- nb_heredoc : %d\n", head->process->first->data, head->nb_heredoc);
	list = head->process->first;
	//printf("list %s\n", list->data);
	while (list && list->type != 33)
	{
		if (list->next)	
			list = list->next;
		else 
			break ;
	}
	//printf("Fin boucle 2 list %s\n", list->data);
	while (i < head->nb_heredoc && list && k < totalhd)
	{
		//printf("DEbut boucle 3 i = %d ---- K = %d --- head->heredoc %d --- list data %s --- %d==totalhd\n", i, k, head->nb_heredoc, list->data, totalhd);
		fi = fork();
		//printf("%d \n", fi);
		if	(fi < 0)
		{
			error_msgs(errno, "Fork failed");
			return (-200);
		}
		ft_sig_fork(fi);
		//printf("total nb heredoc %d \n", totalhd);
		if (fi == 0)
		{
			//printf("IIIRGEEENNT %s \n", list->data);
			if (list->next->type == 35 || list->next->type == 36 || list->next->type == 37)
				manage_one_redir(list->next, head);
			else
			{
				while (list && list->type != 33)
				{
					if (list->next)	
						list = list->next;
					else 
						break ;
				}
				//printf("IIIRGEEENNT 22222222222222 %s \n", list->next->data);
				manage_one_redir(list->next, head);
			}
			exit(1);
		}	
		waiting_child_hd(fi);
		manage_signal();
		file = open(".hd1", O_RDONLY);
		if	(file < 0)
		{
			error_msgs(errno, "Temporary file failed");
			return (-200);
		}
		tmp = get_next_line(file);
		//printf("tmp ==> %s\n", tmp);
		while (tmp != NULL)
		{
			//printf("tmp ==> %s\n", tmp);
			node_toadd = ft_strjoin(node_toadd, tmp);
			free(tmp);
			tmp = get_next_line(file);	
		}
		//printf("prout\n");
		close(file);
		if (list->next)
			list = list->next;
		else
			break ;
		if (list->type == 35 || list->type == 36 || list->type == 37)
			insert_node(list->data, node_toadd, &head);
		else
		{
			while(list && (list->type != 35 && list->type != 36 && list->type != 37))
			{
				if (list->next)
					list = list->next;
				else
					break ;
			}
			insert_node(list->data, node_toadd, &head);
		}
		node_toadd = NULL;
		tmp = NULL;
		//printf("HOLLAA %s --  \n", list->data);
		while(list && list->type != 33)
		{
			if (list->next)
				list = list->next;
			else
				break ;
		}
		i ++;
		k ++;
		if (i == head->nb_heredoc)
		{
			i = 0;
			if (head->next)
			{
				head = head->next;
				list = head->process->first;
			}
			else
				break ;
		}
	}
	return (0);
}


int	check_tot_heredoc(t_flist **list)
{
	t_flist	*gr_list;
	int		tota_heredoc;

	tota_heredoc = 0;
	gr_list = *list;
	while(gr_list)
	{
		if (gr_list->nb_heredoc > 0)
			tota_heredoc += gr_list->nb_heredoc;
		if (gr_list->next)
			gr_list = gr_list->next;
		else
			break ;
	}
	return (tota_heredoc);
}

t_flist	*parse_args(char	*entry, char **env)
{
	t_dblist	*fin_li;
	t_flist		*gr_list;
	int			tota_heredoc;

	//printf("test1");
	(void)**env;
	fin_li = get_tokens(entry);
	tota_heredoc = 0;
	if	(!fin_li)
		return (NULL);
	gr_list = get_processes(fin_li);
	counting(&gr_list);
	// affiche(gr_list->next->process);
	if (my_lstsize(&gr_list) == 1)
	{
		if	(simple_block_p(&gr_list) == -200)
			return (NULL);
		// affiche(gr_list->process);
	}
	else if	(my_lstsize(&gr_list) > 1)
	{
		tota_heredoc = check_tot_heredoc(&gr_list);
		if (tota_heredoc >= 1)
		{
			if	(multiple_block_p(&gr_list, tota_heredoc) == -200)
				return (NULL);
		}
	}
	//printf("dataaaaa -- >%s, siiizeeuh = %zu\n", gr_list->process->first->next->data, ft_strlen(gr_list->process->first->next->data));
	return (gr_list);
}
