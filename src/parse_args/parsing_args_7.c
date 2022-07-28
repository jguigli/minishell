/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:03:36 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:03:38 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rules_for_lbracket(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_LBRACKET][CHR_LBRACKET] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_WORD] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_LBRACKET] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_RBRACKET] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_DOL] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_SP] = 0;
	tok_info->grul[TOKEN_LBRACKET][CHR_EOF] = 0;
	tok_info->grul[TOKEN_LBRACKET][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_ESP] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_BS] = 1;
	tok_info->grul[TOKEN_LBRACKET][CHR_UNDS] = 1;
}

void	rules_for_rbracket(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_RBRACKET][CHR_RBRACKET] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_WORD] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_LBRACKET] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_RBRACKET] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_DOL] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_SP] = 0;
	tok_info->grul[TOKEN_RBRACKET][CHR_EOF] = 0;
	tok_info->grul[TOKEN_RBRACKET][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_ESP] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_BS] = 1;
	tok_info->grul[TOKEN_RBRACKET][CHR_UNDS] = 1;
}

void	rules_for_diez(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DIEZ][CHR_DIEZ] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DOL] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_SP] = 0;
	tok_info->grul[TOKEN_DIEZ][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DIEZ][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_ESP] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_BS] = 1;
}

void	rules_for_colon(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_COLON][CHR_COLON] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_DOL] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_SP] = 0;
	tok_info->grul[TOKEN_DIEZ][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DIEZ][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_ESP] = 1;
	tok_info->grul[TOKEN_DIEZ][CHR_BS] = 1;
}

void	rules_for_others(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_BT][CHR_BT] = 1;
	tok_info->grul[TOKEN_LEMBRACE][CHR_LEMBRACE] = 1;
	tok_info->grul[TOKEN_REMBRACE][CHR_REMBRACE] = 1;
	tok_info->grul[TOKEN_PERCENT][CHR_PERCENT] = 1;
	tok_info->grul[TOKEN_UACC][CHR_UACC] = 1;
	tok_info->grul[TOKEN_CIRC][CHR_CIRC] = 1;
	tok_info->grul[TOKEN_NL][CHR_NL] = 1;
	tok_info->grul[TOKEN_COMA][CHR_COMA] = 1;
	tok_info->grul[TOKEN_SEMI][CHR_SEMI] = 1;
}
