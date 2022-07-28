/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:59:13 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:59:15 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rules_for_lbrace_bis(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_LBRACE][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_EOF] = 0;
	tok_info->grul[TOKEN_LBRACE][CHR_ESP] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_DASH] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_AROB] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_RRED] = 0;
	tok_info->grul[TOKEN_LBRACE][CHR_LRED] = 0;
	tok_info->grul[TOKEN_LBRACE][CHR_CIRC] = 1;
	tok_info->grul[TOKEN_LBRACE][CHR_EQ] = 1;
}

void	rules_for_rbrace(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_RBRACE][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_TILDE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_LEMBRACE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_REMBRACE] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_COMA] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_WILDC] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_WORD] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_DOL] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_SEMI] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_BANG] = 0;
	tok_info->grul[TOKEN_RBRACE][CHR_BS] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_SP] = 0;
	tok_info->grul[TOKEN_RBRACE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_QUERY] = 1;
}

void	rules_for_rbrace_bis(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_RBRACE][CHR_UNDS] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_PLUS] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_DIEZ] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_EOF] = 0;
	tok_info->grul[TOKEN_RBRACE][CHR_ESP] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_DASH] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_AROB] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_RRED] = 0;
	tok_info->grul[TOKEN_RBRACE][CHR_LRED] = 0;
	tok_info->grul[TOKEN_RBRACE][CHR_CIRC] = 1;
	tok_info->grul[TOKEN_RBRACE][CHR_EQ] = 1;
}

void	rules_for_pipe(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_PIPE][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_PIPE][CHR_ESP] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_WORD] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_SP] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_BS] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_SLASH] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_DIGIT] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_COMA] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_EOF] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_LRED] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_SQUOTE] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_DQUOTE] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_BQUOTE] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_LPAREN] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_RPAREN] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_LBRACE] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_RBRACE] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_DOT] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_DASH] = 0;
	tok_info->grul[TOKEN_PIPE][CHR_BANG] = 0;
}

void	rules_for_dol(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DOL][CHR_DOL] = 1;
	tok_info->grul[TOKEN_DOL][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DOL][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DOL][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_BQUOTE] = 0;
	tok_info->grul[TOKEN_DOL][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DOL][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DOL][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_LEMBRACE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_REMBRACE] = 1;
	tok_info->grul[TOKEN_DOL][CHR_COMA] = 1;
	tok_info->grul[TOKEN_DOL][CHR_COLON] = 1;
	tok_info->grul[TOKEN_DOL][CHR_QUERY] = 1;
	tok_info->grul[TOKEN_DOL][CHR_UNDS] = 1;
	tok_info->grul[TOKEN_DOL][CHR_EQ] = 1;
	tok_info->grul[TOKEN_DOL][CHR_BANG] = 0;
	tok_info->grul[TOKEN_DOL][CHR_ESP] = 1;
}
