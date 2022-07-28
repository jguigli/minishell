/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:00:13 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:00:14 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rules_for_dol_bis(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DOL][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DOL][CHR_SP] = 0;
	tok_info->grul[TOKEN_DOL][CHR_DOT] = 1;
	tok_info->grul[TOKEN_DOL][CHR_DASH] = 1;
	tok_info->grul[TOKEN_DOL][CHR_PERCENT] = 1;
	tok_info->grul[TOKEN_DOL][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DOL][CHR_BS] = 1;
}

void	rules_for_dquote(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_DQUOTE][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_WORD] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_LRED] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_RRED] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_COMA] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_DOL] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_SP] = 0;
	tok_info->grul[TOKEN_DQUOTE][CHR_BS] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_EOF] = 0;
	tok_info->grul[TOKEN_DQUOTE][CHR_EQ] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_COLON] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_ESP] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_DQUOTE][CHR_DASH] = 1;
}

void	rules_for_squote(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_SQUOTE][CHR_SQUOTE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_WORD] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_LRED] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_RRED] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_COMA] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DOL] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_SP] = 0;
	tok_info->grul[TOKEN_SQUOTE][CHR_BS] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_EOF] = 0;
	tok_info->grul[TOKEN_SQUOTE][CHR_EQ] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_COLON] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_ESP] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SQUOTE][CHR_DASH] = 1;
}

void	rules_for_slash(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_SLASH][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_WORD] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_COMA] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DOL] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_SP] = 0;
	tok_info->grul[TOKEN_SLASH][CHR_EOF] = 0;
	tok_info->grul[TOKEN_SLASH][CHR_BS] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_ESP] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_BS] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DOT] = 1;
	tok_info->grul[TOKEN_SLASH][CHR_DASH] = 1;
}

void	rules_for_bslash(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_BS][CHR_BS] = 1;
	tok_info->grul[TOKEN_BS][CHR_DIGIT] = 1;
	tok_info->grul[TOKEN_BS][CHR_WORD] = 1;
	tok_info->grul[TOKEN_BS][CHR_DQUOTE] = 1;
	tok_info->grul[TOKEN_BS][CHR_BQUOTE] = 1;
	tok_info->grul[TOKEN_BS][CHR_LPAREN] = 1;
	tok_info->grul[TOKEN_BS][CHR_RPAREN] = 1;
	tok_info->grul[TOKEN_BS][CHR_LBRACE] = 1;
	tok_info->grul[TOKEN_BS][CHR_RBRACE] = 1;
	tok_info->grul[TOKEN_BS][CHR_COMA] = 1;
	tok_info->grul[TOKEN_BS][CHR_DOL] = 1;
	tok_info->grul[TOKEN_BS][CHR_PIPE] = 1;
	tok_info->grul[TOKEN_BS][CHR_SP] = 0;
	tok_info->grul[TOKEN_BS][CHR_EOF] = 0;
	tok_info->grul[TOKEN_BS][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_BS][CHR_DOT] = 1;
	tok_info->grul[TOKEN_BS][CHR_ESP] = 1;
	tok_info->grul[TOKEN_BS][CHR_BS] = 1;
	tok_info->grul[TOKEN_BS][CHR_DOT] = 1;
	tok_info->grul[TOKEN_BS][CHR_DASH] = 1;
}
