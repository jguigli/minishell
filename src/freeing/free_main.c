/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:05:36 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/22 19:31:59 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_datas(t_datas *data)
{
	t_datas	*current;
	t_datas	*to_free;

	current = data;
	while (current)
	{
		to_free = current;
		if (current->next)
			current = current->next;
		else
		{
			if (to_free->data)
				free(to_free->data);
			free(to_free);
			break ;
		}
		if (to_free->data)
			free(to_free->data);
		free(to_free);
	}
}

void	free_dblist(t_dblist *first)
{
	if (first->first && first->first->data)
		free_datas(first->first);
	if (first->in)
		free(first->in);
	free(first);
}

void	free_flist(t_flist	*first)
{
	t_flist	*current;
	t_flist	*to_free;
	int		i;

	current = first;
	i = 0;
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
			i ++;
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
	i = 0;
	if (main->export)
	{
		while (main->export[i])
			free(main->export[i++]);
		free(main->export);
	}
	if (main->start)
		free_flist(main->start);
	if (main->my_prompt)
		free(main->my_prompt);
	if (main->exec_c)
		free_exec_complex(main->exec_c);
	if (main->exec_s)
		free_exec_simple(main->exec_s);
	free(main);
}

void	ft_free_hd(t_main *main)
{
	int	i;

	i = 0;
	if (main->env)
	{
		while (main->env[i])
			free(main->env[i++]);
		free(main->env);
	}
	i = 0;
	if (main->export)
	{
		while (main->export[i])
			free(main->export[i++]);
		free(main->export);
	}
	if (main->start)
		free_flist(main->start);
	if (main->my_prompt)
		free(main->my_prompt);
	free(main);
}
