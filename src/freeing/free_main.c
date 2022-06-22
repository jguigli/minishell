#include "../../includes/minishell.h"

void	free_datas(t_datas *data)
{
	if (data->data)
		free(data->data);
}

void	free_dblist(t_dblist *first)
{
	t_datas	*current;
	t_datas	*to_free;

	current = first->first;
	while (current)
	{
		to_free = current;
		if (current->next)
				current = current->next;
			else
				break ; //rajouter condition de secu
		free_datas(to_free);
		free(to_free);
	}
	//free (first);
}

void	free_flist(t_flist	*first)
{
	t_flist	*current;
	t_flist	*to_free;

	current = first;
	if (first)
	{
		while (current)
		{
			to_free = current;
			free_dblist(current->process);
			if (current->next)
				current = current->next;
			else
				break ;
			free(to_free);
		}
	}
}

void	ft_free(t_main *main)
{
	int	i;

	i = 0;
	if (main->env)
	{
		while (main->env[i])
			free(main->env[i++]);
		free(main->env);
	}
	if (main->start)
		free_flist(main->start);
	// if (main->exec_c)
	// 	free_exec_complex(main->exec_c);
	// if (main->exec_s)
	// 	free_exec_simple(main->exec_s);
	free(main);
}
