/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:03:22 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:03:24 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_tokens_twentyfive(t_glob_infos *tok_info)
{
	tok_info->gtt[CHR_SP] = TOKEN_SP;
	tok_info->gtt[CHR_BT] = TOKEN_BT;
	tok_info->gtt[CHR_UACC] = TOKEN_UACC;
	tok_info->gtt[CHR_PLUS] = TOKEN_PLUS;
	tok_info->gtt[CHR_CIRC] = TOKEN_CIRC;
	tok_info->gtt[CHR_AND] = TOKEN_AND;
	tok_info->gtt[CHR_PIPE] = TOKEN_PIPE;
	tok_info->gtt[CHR_WORD] = TOKEN_WORD;
	tok_info->gtt[CHR_ESCAPE] = TOKEN_WORD;
	tok_info->gtt[CHR_DIEZ] = TOKEN_DIEZ;
	tok_info->gtt[CHR_RRED] = TOKEN_RRED;
	tok_info->gtt[CHR_LRED] = TOKEN_LRED;
	tok_info->gtt[CHR_LPAREN] = TOKEN_LPAREN;
	tok_info->gtt[CHR_RPAREN] = TOKEN_RPAREN;
	tok_info->gtt[CHR_LEMBRACE] = TOKEN_LEMBRACE;
	tok_info->gtt[CHR_REMBRACE] = TOKEN_REMBRACE;
	tok_info->gtt[CHR_LBRACKET] = TOKEN_LBRACKET;
	tok_info->gtt[CHR_RBRACKET] = TOKEN_RBRACKET;
	tok_info->gtt[CHR_DIGIT] = TOKEN_WORD;
}

void	init_tokens_fifty(t_glob_infos *tok_info)
{
	tok_info->gtt[CHR_RBRACE] = TOKEN_RBRACE;
	tok_info->gtt[CHR_LPAREN] = TOKEN_LPAREN;
	tok_info->gtt[CHR_RPAREN] = TOKEN_RPAREN;
	tok_info->gtt[CHR_BQUOTE] = TOKEN_BQUOTE;
	tok_info->gtt[CHR_EQ] = TOKEN_EQ;
	tok_info->gtt[CHR_EOF] = TOKEN_EOF;
	tok_info->gtt[CHR_SLASH] = TOKEN_SLASH;
	tok_info->gtt[CHR_DOT] = TOKEN_DOT;
	tok_info->gtt[CHR_COMA] = TOKEN_COMA;
	tok_info->gtt[CHR_DASH] = TOKEN_DASH;
	tok_info->gtt[CHR_ESP] = TOKEN_ESP;
	tok_info->gtt[CHR_BS] = TOKEN_BS;
	tok_info->gtt[CHR_UNDS] = TOKEN_UNDS;
	tok_info->gtt[CHR_NL] = TOKEN_NL;
	tok_info->gtt[CHR_QUERY] = TOKEN_QUERY;
	tok_info->gtt[CHR_AROB] = TOKEN_AROB;
	tok_info->gtt[CHR_TILDE] = TOKEN_TILDE;
	tok_info->gtt[CHR_COLON] = TOKEN_COLON;
}

void	init_tokens(t_glob_infos *tok_info)
{
	init_tokens_twentyfive(tok_info);
	init_tokens_fifty(tok_info);
	init_tokens_bis(tok_info);
}

void	rules_for_word(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_WORD][CHR_WORD] = 1;
	tok_info->grul[TOKEN_WORD][CHR_TILDE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_WORD][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_WORD][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_WORD][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_LEMBRACE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_REMBRACE] = 1;
	tok_info->grul[TOKEN_WORD][CHR_COMA] = 1;
	tok_info->grul[TOKEN_WORD][CHR_WILDC] = 1;
	tok_info->grul[TOKEN_WORD][CHR_DOL] = 1;
}

void	rules_for_word_bis(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_WORD][CHR_UNDS] = 1;
	tok_info->grul[TOKEN_WORD][CHR_ESP] = 1;
	tok_info->grul[TOKEN_WORD][CHR_DASH] = 1;
	tok_info->grul[TOKEN_WORD][CHR_AROB] = 1;
	tok_info->grul[TOKEN_WORD][CHR_RRED] = 0;
	tok_info->grul[TOKEN_WORD][CHR_LRED] = 0;
	tok_info->grul[TOKEN_WORD][CHR_CIRC] = 1;
	tok_info->grul[TOKEN_WORD][CHR_EQ] = 1;
}
