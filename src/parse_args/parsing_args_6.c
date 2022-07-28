/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:02:56 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:58 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rules_for_esp(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_ESP][CHR_ESP] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_ESP][CHR_WORD] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_ESP][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_ESP][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_ESP][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_ESP][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_ESP][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_ESP][CHR_COMA] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DOL] = 1;
	tok_info->grul[TOKEN_ESP][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_ESP][CHR_SP] = 1;
	tok_info->grul[TOKEN_ESP][CHR_EOF] = 0;
	tok_info->grul[TOKEN_ESP][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DOT] = 1;
	tok_info->grul[TOKEN_ESP][CHR_ESP] = 1;
	tok_info->grul[TOKEN_ESP][CHR_BS] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DOT] = 1;
	tok_info->grul[TOKEN_ESP][CHR_DASH] = 1;
}

void	rules_for_semi(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_SEMI][CHR_SEMI] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_WORD] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_COMA] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DOL] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_SP] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_EOF] = 0;
	tok_info->grul[TOKEN_SEMI][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_ESP] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_BS] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_DASH] = 1;
}

void	rules_for_coma(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_COMA][CHR_COMA] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_COMA][CHR_WORD] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_COMA][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_COMA][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_COMA][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_COMA][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_COMA][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_COMA][CHR_COMA] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DOL] = 1;
	tok_info->grul[TOKEN_COMA][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_COMA][CHR_SP] = 0;
	tok_info->grul[TOKEN_COMA][CHR_EOF] = 0;
	tok_info->grul[TOKEN_COMA][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DOT] = 1;
	tok_info->grul[TOKEN_COMA][CHR_ESP] = 1;
	tok_info->grul[TOKEN_COMA][CHR_BS] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DOT] = 1;
	tok_info->grul[TOKEN_COMA][CHR_DASH] = 1;
}

void	rules_for_dot(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DOT][CHR_DOT] = 1;
	tok_info->grul[TOKEN_DOT][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DOT][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DOT][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DOT][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_DOT][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DOT][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DOT][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DOT][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DOT][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_DOT][CHR_SP] = 0;
	tok_info->grul[TOKEN_DOT][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DOT][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DOT][CHR_ESP] = 1;
	tok_info->grul[TOKEN_DOT][CHR_BS] = 1;
	tok_info->grul[TOKEN_DOT][CHR_DASH] = 1;
}

void	rules_for_dash(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DASH][CHR_DASH] = 1;
	tok_info->grul[TOKEN_DASH][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DASH][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DASH][CHR_EQ] = 1;
	tok_info->grul[TOKEN_DASH][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DASH][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_DASH][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_DASH][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DASH][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DASH][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DASH][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DASH][CHR_DASH] = 1;
	tok_info->grul[TOKEN_DASH][CHR_DOL] = 1;
	tok_info->grul[TOKEN_DASH][CHR_PIPE] = 0;
	tok_info->grul[TOKEN_DASH][CHR_SP] = 0;
	tok_info->grul[TOKEN_DASH][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DASH][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DASH][CHR_DASH] = 1;
	tok_info->grul[TOKEN_DASH][CHR_ESP] = 1;
	tok_info->grul[TOKEN_DASH][CHR_BS] = 1;
}
