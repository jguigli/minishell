#include "../../includes/minishell.h"

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