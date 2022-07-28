/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manage_redir_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:07:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:07:48 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	output_r(t_datas *output_r, t_main *main)
{
	if (main->my_fds[0] != -1000 && main->my_fds[0] != -1)
	{
		dup2(main->my_oldfds[0], STDOUT_FILENO);
		close(main->my_fds[0]);
	}
	if (output_r->type == 6)
		main->my_fds[0] = open(output_r->next->data,
				O_TRUNC | O_CREAT | O_RDWR, 000644);
	if (output_r->type == 38)
		main->my_fds[0] = open(output_r->next->data,
				O_CREAT | O_RDWR | O_APPEND, 000644);
	if (main->my_fds[0] < 0)
	{
		error_msgs(errno, output_r->next->data);
		return (-5);
	}
	dup2(main->my_fds[0], STDOUT_FILENO);
	return (0);
}

void	close_openfds(t_main *main)
{
	if (main->my_fds[1] != -1000 && main->my_fds[1] != -1)
	{
		dup2(main->my_oldfds[1], STDIN_FILENO);
		close(main->my_fds[1]);
	}
	if (main->my_fds[0] != -1000 && main->my_fds[0] != -1)
	{
		dup2(main->my_oldfds[0], STDOUT_FILENO);
		close(main->my_fds[0]);
	}
}

int	ipr_islred(t_datas *input_r, t_main *main)
{
	if (input_r->type == 7)
	{
		main->my_fds[1] = open(input_r->next->data, O_RDONLY, 000644);
		if (main->my_fds[1] < 0)
			error_msgs(errno, input_r->next->data);
	}
	return (main->my_fds[1]);
}

int	input_r(t_datas *input_r, t_main *main)
{
	if (main->my_fds[1] != -1000 && main->my_fds[1] != -1)
	{
		dup2(main->my_oldfds[1], STDIN_FILENO);
		close(main->my_fds[1]);
	}
	main->my_fds[1] = ipr_islred(input_r, main);
	if (main->my_fds[1] < 0 && main->my_fds[1] != -1000)
		return (-5);
	else if (input_r->type == 33)
	{
		main->my_fds[1] = open(".hd1", O_RDONLY);
		if (main->my_fds[1] < 0)
			return (-5);
	}
	if (dup2(main->my_fds[1], STDIN_FILENO) == -1)
		return (5);
	close(main->my_fds[1]);
	return (0);
}

t_datas	*delnode_empty(t_datas *current, t_flist *list)
{
	t_datas		*stock_curr;

	list->process->in->incr = 0;
	while (current && current->data[0] == '\0'
		&& current->type != 13 && current->type != 12)
	{
		stock_curr = current;
		if (current->next)
		{
			current = current->next;
			list->process->in->incr = 1;
		}
		else
		{
			free(stock_curr->data);
			free(stock_curr);
			return (NULL);
		}
		free(stock_curr->data);
		free(stock_curr);
		list->process->first = current;
	}
	return (current);
}
