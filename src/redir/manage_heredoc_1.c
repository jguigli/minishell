/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:48:22 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/19 21:02:07 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_datas	*check_for_expansion(t_datas *copy)
{
	if (copy->type != 36 && copy->type != 37)
	{
		if (!count_quote(copy->data))
			copy->expansion = 1;
		else
			copy->data = hd_removedquote(copy->data);
	}
	else if (copy->type == 36 || copy->type == 37)
		copy->data = hd_removedquote(copy->data);
	return (copy);
}

int	check_break(char *buf, t_flist *gr_list, t_datas *copy, t_main *main)
{
	(void)gr_list;
	(void)main;
	if (!ft_strcmp(copy->data, buf))
	{
		free(buf);
		return (0);
	}
	return (1);
}

int	check_ctrd(char *buf, int file, t_flist *gr_list, t_main *main)
{
	if (buf == NULL)
	{
		free(buf);
		close(file);
		free_flist(gr_list);
		ft_free(main);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}

void	the_end(int file, t_main *m, t_flist *head2)
{
	close(file);
	free_flist(head2);
	ft_free_hd(m);
	exit(EXIT_SUCCESS);
}

void	manage_one_redir(t_datas *del, t_flist *gl, t_flist *head2, t_main *m)
{
	t_datas	*copy;
	int		file;
	char	*buf;

	copy = del;
	copy = check_for_expansion(copy);
	file = open(".hd1", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	fail_file(file);
	while (1)
	{
		buf = readline("> ");
		if (check_ctrd(buf, file, gl, m) == 0)
			break ;
		if (check_break(buf, gl, copy, m) == 0)
			break ;
		if (copy->expansion)
			buf = hd_expansion(buf, m);
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	the_end(file, m, head2);
}
