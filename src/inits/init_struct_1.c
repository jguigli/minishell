/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:04:49 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:04:51 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_glob_infos	*initst_infos(void)
{
	t_glob_infos	*tok_info;

	tok_info = ft_calloc(1, sizeof(t_glob_infos));
	if (!tok_info)
		return (NULL);
	init_classes(tok_info);
	init_tokens(tok_info);
	init_rules(tok_info);
	init_types(tok_info);
	tok_info->dq = 1;
	tok_info->sq = 1;
	return (tok_info);
}

t_dblist	*init_linked_list(void)
{
	t_dblist	*liste;

	liste = ft_calloc(1, sizeof(t_dblist));
	if (!liste)
		exit(EXIT_FAILURE);
	liste->in = initst_infos();
	liste->first = NULL;
	return (liste);
}

t_flist	*init_struct_flist(void)
{
	t_flist	*finli;

	finli = ft_calloc(1, sizeof(t_flist));
	if (!finli)
		exit(EXIT_FAILURE);
	finli->process = init_linked_list();
	return (finli);
}

t_main	*init_main(void)
{
	t_main	*main;

	main = ft_calloc(1, sizeof(t_main));
	if (!main)
		return (NULL);
	main->start = NULL;
	main->env = NULL;
	main->export = NULL;
	main->exec_c = NULL;
	main->exec_s = NULL;
	main->my_prompt = NULL;
	main->my_fds[0] = -1000;
	main->my_fds[1] = -1000;
	main->my_oldfds[0] = -200;
	main->my_oldfds[1] = -200;
	return (main);
}
