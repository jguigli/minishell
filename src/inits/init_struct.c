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

	//liste = ft_calloc(1, sizeof(t_dblist));
	liste = ft_calloc(1,sizeof(t_dblist));
	if (!liste)
		exit(EXIT_FAILURE);
	// liste->number = 0;
	// liste->first = NULL;
	// liste->last = NULL;
	liste->infos = initst_infos();
	return (liste);
}

t_flist	*init_struct_flist()
{
	t_flist	*finli;

	//liste = ft_calloc(1, sizeof(t_dblist));
	finli = ft_calloc(1, sizeof(t_flist));
	if (!finli)
		exit(EXIT_FAILURE);
	finli->process = init_linked_list();
	// finli->next= NULL;
	// finli->previous = NULL;
	// finli->nb_rred = 0;
	// finli->nb_rred_app = 0;
	// finli->nb_lred = 0;
	// finli->nb_heredoc = 0;
	// finli->nb_options = 0;
	return (finli);
}

void	init_global(void)
{
	g.status = 0;
	g.my_fds[0] = -1000;
	g.my_fds[1] = -1000;
	g.my_oldfds[0] = -200;
	g.my_oldfds[1] = -200;
	g.sigintos = 0;
}