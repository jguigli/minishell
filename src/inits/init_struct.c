#include "../../includes/minishell.h"

t_dblist	*init_linked_list()
{
	t_dblist	*liste;

	//liste = ft_calloc(1, sizeof(t_dblist));
	liste = malloc(sizeof(t_dblist));
	if (!liste)
		exit(EXIT_FAILURE);
	liste->number = 0;
	liste->first = NULL;
	liste->last = NULL;
	liste->infos = initst_infos();
	return (liste);
}