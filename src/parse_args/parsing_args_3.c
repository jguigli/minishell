/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:03:08 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:03:12 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rules_for_rred(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_RRED][CHR_RRED] = 1;
	tok_info->grul[TOKEN_RRED][CHR_DIGIT] = 0;
	tok_info->grul[TOKEN_RRED][CHR_COMA] = 1;
	tok_info->grul[TOKEN_RRED][CHR_WORD] = 0;
	tok_info->grul[TOKEN_RRED][CHR_SP] = 0;
	tok_info->grul[TOKEN_RRED][CHR_EOF] = 0;
	tok_info->grul[TOKEN_RRED][CHR_LRED] = 1;
	tok_info->grul[TOKEN_RRED][CHR_SQUOTE] = 0;
	tok_info->grul[TOKEN_RRED][CHR_DQUOTE] = 0;
	tok_info->grul[TOKEN_RRED][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_RRED][CHR_LPAREN] = 0;
	tok_info->grul[TOKEN_RRED][CHR_RPAREN] = 0;
	tok_info->grul[TOKEN_RRED][CHR_LBRACE] = 0;
	tok_info->grul[TOKEN_RRED][CHR_RBRACE] = 0;
	tok_info->grul[TOKEN_RRED][CHR_BANG] = 0;
	tok_info->grul[TOKEN_RRED][CHR_ESP] = 0;
	tok_info->grul[TOKEN_RRED][CHR_DOT] = 0;
	tok_info->grul[TOKEN_RRED][CHR_DASH] = 1;
}

void	rules_for_lred(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_LRED][CHR_LRED] = 1;
	tok_info->grul[TOKEN_LRED][CHR_DIGIT] = 0;
	tok_info->grul[TOKEN_LRED][CHR_WORD] = 0;
	tok_info->grul[TOKEN_LRED][CHR_COMA] = 0;
	tok_info->grul[TOKEN_LRED][CHR_SP] = 0;
	tok_info->grul[TOKEN_LRED][CHR_EOF] = 0;
	tok_info->grul[TOKEN_LRED][CHR_RRED] = 1;
	tok_info->grul[TOKEN_LRED][CHR_SQUOTE] = 0;
	tok_info->grul[TOKEN_LRED][CHR_DQUOTE] = 0;
	tok_info->grul[TOKEN_LRED][CHR_BQUOTE] = 0;
	tok_info->grul[TOKEN_LRED][CHR_LPAREN] = 0;
	tok_info->grul[TOKEN_LRED][CHR_RPAREN] = 0;
	tok_info->grul[TOKEN_LRED][CHR_LBRACE] = 0;
	tok_info->grul[TOKEN_LRED][CHR_RBRACE] = 0;
	tok_info->grul[TOKEN_LRED][CHR_ESP] = 0;
	tok_info->grul[TOKEN_LRED][CHR_DOT] = 0;
	tok_info->grul[TOKEN_LRED][CHR_DASH] = 0;
	tok_info->grul[TOKEN_LRED][CHR_BANG] = 0;
}

void	rules_for_bang(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_BANG][CHR_BANG] = 1;
	tok_info->grul[TOKEN_BANG][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_BANG][CHR_COMA] = 1;
	tok_info->grul[TOKEN_BANG][CHR_WORD] = 1;
	tok_info->grul[TOKEN_BANG][CHR_SP] = 0;
	tok_info->grul[TOKEN_BANG][CHR_EOF] = 0;
	tok_info->grul[TOKEN_BANG][CHR_LRED] = 1;
	tok_info->grul[TOKEN_BANG][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_BANG][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_BANG][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_BANG][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_BANG][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_BANG][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_BANG][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_BANG][CHR_ESP] = 1;
	tok_info->grul[TOKEN_BANG][CHR_EQ] = 1;
	tok_info->grul[TOKEN_BANG][CHR_DOT] = 1;
	tok_info->grul[TOKEN_BANG][CHR_DASH] = 1;
	tok_info->grul[TOKEN_BANG][CHR_BS] = 0;
	tok_info->grul[TOKEN_BANG][CHR_SLASH] = 0;
}

void	rules_for_space(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_SP][CHR_SP] = 1;
	tok_info->grul[TOKEN_SP][CHR_DIGIT] = 0;
	tok_info->grul[TOKEN_SP][CHR_SQUOTE] = 0;
	tok_info->grul[TOKEN_SP][CHR_DQUOTE] = 0;
	tok_info->grul[TOKEN_SP][CHR_BQUOTE] = 0;
	tok_info->grul[TOKEN_SP][CHR_LPAREN] = 0;
	tok_info->grul[TOKEN_SP][CHR_RPAREN] = 0;
	tok_info->grul[TOKEN_SP][CHR_LBRACE] = 0;
	tok_info->grul[TOKEN_SP][CHR_RBRACE] = 0;
	tok_info->grul[TOKEN_SP][CHR_COMA] = 0;
	tok_info->grul[TOKEN_SP][CHR_DOL] = 0;
	tok_info->grul[TOKEN_SP][CHR_SEMI] = 0;
	tok_info->grul[TOKEN_SP][CHR_BANG] = 0;
	tok_info->grul[TOKEN_SP][CHR_BS] = 0;
	tok_info->grul[TOKEN_SP][CHR_SP] = 0;
	tok_info->grul[TOKEN_SP][CHR_DOT] = 0;
	tok_info->grul[TOKEN_SP][CHR_SLASH] = 0;
	tok_info->grul[TOKEN_SP][CHR_EOF] = 0;
	tok_info->grul[TOKEN_SP][CHR_ESP] = 0;
	tok_info->grul[TOKEN_SP][CHR_DASH] = 0;
	tok_info->grul[TOKEN_SP][CHR_RRED] = 0;
	tok_info->grul[TOKEN_SP][CHR_LRED] = 0;
	tok_info->grul[TOKEN_SP][CHR_EQ] = 0;
	tok_info->grul[TOKEN_SP][CHR_BANG] = 0;
}

void	rules_for_lbrace(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_LBRACE][CHR_TILDE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_LEMBRACE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_REMBRACE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_COMA] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_WILDC] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DOL] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_SEMI] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_BANG] = 0;
	tok_info->grul[TOKEN_LBRACE][CHR_BS] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_SP] = 0;
	tok_info->grul[TOKEN_LBRACE][CHR_WORD] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_QUERY] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_UNDS] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_PLUS] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DIEZ] = 1;
}
