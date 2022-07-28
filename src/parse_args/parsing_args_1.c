/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:02:19 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:20 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_twenty_five(t_glob_infos *tok_info)
{
	tok_info->gch[' '] = CHR_SP;
	tok_info->gch['\t'] = CHR_SP;
	tok_info->gch[';'] = CHR_SEMI;
	tok_info->gch[','] = CHR_WORD;
	tok_info->gch['$'] = CHR_DOL;
	tok_info->gch['#'] = CHR_DIEZ;
	tok_info->gch['@'] = CHR_WORD;
	tok_info->gch['|'] = CHR_PIPE;
	tok_info->gch['-'] = CHR_DASH;
	tok_info->gch['_'] = CHR_WORD;
	tok_info->gch['>'] = CHR_RRED;
	tok_info->gch['<'] = CHR_LRED;
	tok_info->gch['\"'] = CHR_DQUOTE;
	tok_info->gch['\''] = CHR_SQUOTE;
	tok_info->gch['&'] = CHR_ESP;
	tok_info->gch['~'] = CHR_WORD;
	tok_info->gch['('] = CHR_LBRACE;
	tok_info->gch[')'] = CHR_RBRACE;
	tok_info->gch['*'] = CHR_WILDC;
	tok_info->gch['['] = CHR_WORD;
	tok_info->gch[']'] = CHR_WORD;
	tok_info->gch['{'] = CHR_WORD;
	tok_info->gch['}'] = CHR_WORD;
	tok_info->gch['!'] = CHR_BANG;
	tok_info->gch['?'] = CHR_WORD;
}

void	init_fifty(t_glob_infos *tok_info)
{
	tok_info->gch['a'] = CHR_WORD;
	tok_info->gch['b'] = CHR_WORD;
	tok_info->gch['c'] = CHR_WORD;
	tok_info->gch['d'] = CHR_WORD;
	tok_info->gch['e'] = CHR_WORD;
	tok_info->gch['f'] = CHR_WORD;
	tok_info->gch['g'] = CHR_WORD;
	tok_info->gch['h'] = CHR_WORD;
	tok_info->gch['i'] = CHR_WORD;
	tok_info->gch['j'] = CHR_WORD;
	tok_info->gch['k'] = CHR_WORD;
	tok_info->gch['l'] = CHR_WORD;
	tok_info->gch['m'] = CHR_WORD;
	tok_info->gch['n'] = CHR_WORD;
	tok_info->gch['o'] = CHR_WORD;
	tok_info->gch['p'] = CHR_WORD;
	tok_info->gch['q'] = CHR_WORD;
	tok_info->gch['r'] = CHR_WORD;
	tok_info->gch['s'] = CHR_WORD;
	tok_info->gch['t'] = CHR_WORD;
	init_residus(tok_info);
}

void	init_seventyfive(t_glob_infos *tok_info)
{
	tok_info->gch['G'] = CHR_WORD;
	tok_info->gch['H'] = CHR_WORD;
	tok_info->gch['I'] = CHR_WORD;
	tok_info->gch['J'] = CHR_WORD;
	tok_info->gch['K'] = CHR_WORD;
	tok_info->gch['L'] = CHR_WORD;
	tok_info->gch['M'] = CHR_WORD;
	tok_info->gch['N'] = CHR_WORD;
	tok_info->gch['O'] = CHR_WORD;
	tok_info->gch['P'] = CHR_WORD;
	tok_info->gch['Q'] = CHR_WORD;
	tok_info->gch['R'] = CHR_WORD;
	tok_info->gch['S'] = CHR_WORD;
	tok_info->gch['T'] = CHR_WORD;
	tok_info->gch['U'] = CHR_WORD;
	tok_info->gch['V'] = CHR_WORD;
	tok_info->gch['W'] = CHR_WORD;
	tok_info->gch['X'] = CHR_WORD;
	tok_info->gch['Y'] = CHR_WORD;
	tok_info->gch['Z'] = CHR_WORD;
}

void	init_ninety(t_glob_infos *tok_info)
{
	tok_info->gch['A'] = CHR_WORD;
	tok_info->gch['B'] = CHR_WORD;
	tok_info->gch['C'] = CHR_WORD;
	tok_info->gch['D'] = CHR_WORD;
	tok_info->gch['E'] = CHR_WORD;
	tok_info->gch['F'] = CHR_WORD;
	tok_info->gch['0'] = CHR_WORD;
	tok_info->gch['1'] = CHR_WORD;
	tok_info->gch['2'] = CHR_WORD;
	tok_info->gch['3'] = CHR_WORD;
	tok_info->gch['4'] = CHR_WORD;
	tok_info->gch['5'] = CHR_WORD;
	tok_info->gch['6'] = CHR_WORD;
	tok_info->gch['7'] = CHR_WORD;
	tok_info->gch['8'] = CHR_WORD;
	tok_info->gch['9'] = CHR_WORD;
	tok_info->gch['='] = CHR_WORD;
	tok_info->gch['\0'] = CHR_EOF;
	tok_info->gch['\n'] = CHR_NL;
}

void	init_classes(t_glob_infos *tok_info)
{
	init_twenty_five(tok_info);
	init_fifty(tok_info);
	init_seventyfive(tok_info);
	init_ninety(tok_info);
}
