/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_8bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:57:38 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 11:57:40 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_types_seventyfive(t_glob_infos *tok_info)
{
	tok_info->types[35] = "SIMPLE_DELIM";
	tok_info->types[36] = "DQUOTED_DELIM";
	tok_info->types[37] = "SQUOTED_DELIM";
	tok_info->types[38] = "TOKEN_RRED_APPEND";
	tok_info->types[39] = "TOKEN_HEREDOC_STRING";
	tok_info->types[40] = "TOKEN_NL";
	tok_info->types[41] = "TOKEN_QUERY";
	tok_info->types[42] = "TOKEN_AROB";
	tok_info->types[43] = "TOKEN_DIEZ";
	tok_info->types[44] = "TOKEN_TILDE";
	tok_info->types[45] = "TOKEN_COLON";
	tok_info->types[46] = "TOKEN_PERCENT";
	tok_info->types[47] = "TOKEN_CIRC";
	tok_info->types[48] = "TOKEN_PLUS";
	tok_info->types[50] = "TOKEN_BT";
	tok_info->types[51] = "TOKEN_LEMBRACE";
	tok_info->types[52] = "TOKEN_REMBRACE";
	tok_info->types[53] = "TOKEN_AST";
	tok_info->types[54] = "TOKEN_LBRACKET";
	tok_info->types[55] = "TOKEN_RBRACKET";
	tok_info->types[56] = "TOKEN_DEL";
	tok_info->types[57] = "TOKEN_MAX";
}

void	init_types_fifty(t_glob_infos *tok_info)
{
	tok_info->types[17] = "TOKEN_HYPHEN";
	tok_info->types[18] = "TOKEN_LBRACE";
	tok_info->types[19] = "TOKEN_RBRACE";
	tok_info->types[20] = "TOKEN_WILDC";
	tok_info->types[21] = "TOKEN_FILE";
	tok_info->types[22] = "TOKEN_EQ";
	tok_info->types[23] = "TOKEN_EOF";
	tok_info->types[24] = "TOKEN_CMD";
	tok_info->types[25] = "TOKEN_OPT";
	tok_info->types[26] = "TOKEN_BS";
	tok_info->types[27] = "TOKEN_SLASH";
	tok_info->types[28] = "TOKEN_DOT";
	tok_info->types[29] = "TOKEN_COMA";
	tok_info->types[30] = "TOKEN_ESP";
	tok_info->types[31] = "TOKEN_DASH";
	tok_info->types[32] = "TOKEN_UNDS";
	tok_info->types[33] = "TOKEN_HEREDOC";
	tok_info->types[34] = "TOKEN_HEREDOC_DASH";
}

void	init_types_twentyfive(t_glob_infos *tok_info)
{
	tok_info->types[0] = "TOKEN_ERROR";
	tok_info->types[1] = "TOKEN_SP";
	tok_info->types[2] = "TOKEN_BANG";
	tok_info->types[3] = "TOKEN_AND";
	tok_info->types[4] = "TOKEN_SEMI";
	tok_info->types[5] = "TOKEN_WORD";
	tok_info->types[6] = "TOKEN_RRED";
	tok_info->types[7] = "TOKEN_LRED";
	tok_info->types[8] = "TOKEN_ESCAPE";
	tok_info->types[9] = "TOKEN_DIGIT";
	tok_info->types[10] = "TOKEN_DOL";
	tok_info->types[11] = "TOKEN_PIPE";
	tok_info->types[12] = "TOKEN_SQUOTE";
	tok_info->types[13] = "TOKEN_DQUOTE";
	tok_info->types[14] = "TOKEN_BQUOTE";
	tok_info->types[15] = "TOKEN_LPAREN";
	tok_info->types[16] = "TOKEN_RPAREN";
}

void	init_types(t_glob_infos *tok_info)
{
	init_types_twentyfive(tok_info);
	init_types_fifty(tok_info);
	init_types_seventyfive(tok_info);
}
