#include "../../includes/minishell.h"

void	init_global(t_glob *global)
{
	global = ft_calloc(1, sizeof(t_glob));
	if (!global)
		exit(EXIT_FAILURE);
	global->list = NULL;
}

void	init_linked_list(t_dblist *liste)
{
	liste = ft_calloc(1, sizeof(t_dblist));
	//liste = malloc(sizeof(t_dblist));
	if (!liste)
		exit(EXIT_FAILURE);
	liste->number = 0;
	liste->first = NULL;
	liste->last = NULL;
}