#include "../../includes/minishell.h"

void	free_datas(t_datas *data)
{
	t_datas	*current;
	t_datas	*to_free;

	current = data;
	while (current)
	{
		//printf("ICICICICICICI\n");
		to_free = current;
		if (current->next)
			current = current->next;
		else
		{
			if (to_free->data)
				free(to_free->data);
			free(to_free);
			break ; //rajouter condition de secu
		}
		if (to_free->data)
			free(to_free->data);
		free(to_free);
	}
}

void	free_dblist(t_dblist *first)
{
	if (first->first)
		free_datas(first->first);
	if (first->infos)
		free(first->infos);
	free(first);
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
			{
				free(to_free);
				break ;
			}
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
