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
	tok_info->get_chr_c['\"'] = CHR_WORD;
	tok_info->get_chr_c['\''] = CHR_WORD;
	tok_info->get_chr_c['('] = CHR_WORD;
	tok_info->get_chr_c[')'] = CHR_WORD;
	tok_info->get_chr_c['*'] = CHR_WILDC;
	tok_info->get_chr_c['['] = CHR_LBRACE;
	tok_info->get_chr_c[']'] = CHR_RBRACE;
	tok_info->get_chr_c['!'] = CHR_BANG;
	tok_info->get_chr_c['A','Z'] = CHR_WORD;
	tok_info->get_chr_c['a','z'] = CHR_WORD;
	tok_info->get_chr_c['0','9'] = CHR_DIGIT;
	tok_info->get_chr_c['='] = CHR_EQ;
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
	tok_info->get_tok_type[CHR_DQUOTE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_SQUOTE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_LBRACE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_RBRACE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_LPAREN] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_RPAREN] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_BQUOTE] = TOKEN_WORD;
	tok_info->get_tok_type[CHR_EQ] = TOKEN_EQ;
}

void	init_rules(t_glob_infos *tok_info)
{
	tok_info->get_chr_rules[255][255];

	tok_info->get_chr_rules[TOKEN_SP][CHR_SP] = 0;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_WORD] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_DIGIT] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_SQUOTE] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_DQUOTE] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_BQUOTE] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_LPAREN] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_RPAREN] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_LBRACE] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_RBRACE] = 1;
	// tok_info->get_chr_rules[TOKEN_WORD][CHR_DOL] = 1;
	// tok_info->get_chr_rules[TOKEN_PIPE][CHR_PIPE] = 1;
	// tok_info->get_chr_rules[TOKEN_PIPE][CHR_WORD] = 0;
	// tok_info->get_chr_rules[TOKEN_PIPE][CHR_SP] = 1;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_RRED] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_DIGIT] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_SQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_DQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_BQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_LPAREN] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_RPAREN] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_LBRACE] = 0;
	// tok_info->get_chr_rules[TOKEN_RRED][CHR_RBRACE] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_LRED] = 1;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_DIGIT] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_SQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_DQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_BQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_LPAREN] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_RPAREN] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_LBRACE] = 0;
	// tok_info->get_chr_rules[TOKEN_LRED][CHR_RBRACE] = 0;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_DOL] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_DIGIT] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_SQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_WORD] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_DQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_BQUOTE] = 0;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_LPAREN] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_RPAREN] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_LBRACE] = 1;
	// tok_info->get_chr_rules[TOKEN_DOL][CHR_RBRACE] = 1;
	//printf("test2\n");
}

t_glob_infos	*initst_infos()
{
	t_glob_infos	*tok_info;

	tok_info = malloc(sizeof(t_glob_infos));
	init_classes(tok_info);
	init_tokens(tok_info);
	//init_rules(tok_info);
	printf("test1\n");
	//printf("%d\n", tok_info->get_chr_c['=']);
	return (tok_info);
}


void	parse_args(char	*entry)
{
	t_dblist		*fin_li;

	if (check_quote(entry) == 1 && ft_strlen(entry) > 0)
	{
		fin_li = get_tokens(entry);
		//bst(fin_li);
	}

	else
		return ;
}