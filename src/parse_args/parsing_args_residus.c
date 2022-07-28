/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_residus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:03:52 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:03:54 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_residus(t_glob_infos *tok_info)
{
	tok_info->gch['u'] = CHR_WORD;
	tok_info->gch['v'] = CHR_WORD;
	tok_info->gch['w'] = CHR_WORD;
	tok_info->gch['x'] = CHR_WORD;
	tok_info->gch['y'] = CHR_WORD;
	tok_info->gch['z'] = CHR_WORD;
	tok_info->gch['\\'] = CHR_BS;
	tok_info->gch['/'] = CHR_SLASH;
	tok_info->gch['.'] = CHR_DOT;
	tok_info->gch[':'] = CHR_COLON;
	tok_info->gch['%'] = CHR_WORD;
	tok_info->gch['^'] = CHR_WORD;
	tok_info->gch['+'] = CHR_WORD;
	tok_info->gch['*'] = CHR_WORD;
	tok_info->gch['`'] = CHR_WORD;
}

void	init_tokens_bis(t_glob_infos *tok_info)
{
	tok_info->gtt[CHR_BANG] = TOKEN_BANG;
	tok_info->gtt[CHR_SEMI] = TOKEN_SEMI;
	tok_info->gtt[CHR_DOL] = TOKEN_DOL;
	tok_info->gtt[CHR_WILDC] = TOKEN_WILDC;
	tok_info->gtt[CHR_DQUOTE] = TOKEN_DQUOTE;
	tok_info->gtt[CHR_SQUOTE] = TOKEN_SQUOTE;
	tok_info->gtt[CHR_LBRACE] = TOKEN_LBRACE;
	tok_info->gtt[CHR_PERCENT] = TOKEN_PERCENT;
	tok_info->gtt[CHR_PLUS] = TOKEN_PLUS;
	tok_info->gtt[CHR_AST] = TOKEN_AST;
}

void	rules_bis(t_glob_infos *tok_info)
{
	tok_info->grul[TOKEN_WORD][CHR_SP] = 0;
	tok_info->grul[TOKEN_WORD][CHR_DOT] = 1;
	tok_info->grul[TOKEN_WORD][CHR_SLASH] = 1;
	tok_info->grul[TOKEN_WORD][CHR_QUERY] = 1;
	tok_info->grul[TOKEN_WORD][CHR_UNDS] = 1;
	tok_info->grul[TOKEN_WORD][CHR_PLUS] = 1;
	tok_info->grul[TOKEN_WORD][CHR_DIEZ] = 1;
	tok_info->grul[TOKEN_WORD][CHR_EOF] = 0;
	tok_info->grul[TOKEN_WORD][CHR_SEMI] = 1;
	tok_info->grul[TOKEN_WORD][CHR_BANG] = 0;
	tok_info->grul[TOKEN_WORD][CHR_BS] = 1;
}

void	init_rules_bis(t_glob_infos *tok_info)
{
	rules_for_rbrace(tok_info);
	rules_for_rbrace_bis(tok_info);
	rules_for_rred(tok_info);
	rules_for_semi(tok_info);
	rules_for_slash(tok_info);
	rules_for_space(tok_info);
	rules_for_squote(tok_info);
	rules_for_word(tok_info);
	rules_for_word_bis(tok_info);
	rules_bis(tok_info);
}

int	check_exitstatus(int exit_status, int i, int tothd, t_main *main)
{
	if (exit_status == 130)
	{
		g_status = exit_status;
		main->sigintos = 50;
		manage_signal();
		return (-30);
	}
	if (exit_status == 1)
	{
		write(2, "minishell: warning: here-document", 35);
		write(2, " delimited by end-of-file (wanted delimiteur)\n", 47);
		if (i == tothd - 1)
		{
			main->i = 0;
			manage_signal();
		}
	}
	return (0);
}
