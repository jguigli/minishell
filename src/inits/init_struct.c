#include "../../includes/minishell.h"

t_glob_infos	*initst_infos()
{
	t_glob_infos	*tok_info;

	tok_info = malloc(sizeof(t_glob_infos));
	if (!tok_info)
		return (NULL);
	init_classes(tok_info);
	init_tokens(tok_info);
	init_rules(tok_info);
	return (tok_info);
}

t_dblist	*init_linked_list()
{
	t_dblist	*liste;

	liste = ft_calloc(1,sizeof(t_dblist));
	if (!liste)
		exit(EXIT_FAILURE);
	liste->infos = initst_infos();
	return (liste);
}

t_flist	*init_struct_flist()
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
	main->start = init_struct_flist();
	main->my_fds[0] = -1000;
	main->my_fds[1] = -1000;
	main->my_oldfds[0] = -200;
	main->my_oldfds[1] = -200;
	return (main);
}