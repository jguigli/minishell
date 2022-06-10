#include "../../includes/minishell.h"

int	output_r(t_datas *output_r)
{
	int file;
	int	old_fd;

	if	(output_r->type == 6)
		file = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	if	(output_r->type == 38)
		file = open(output_r->next->data, O_CREAT | O_RDWR | O_APPEND, 000644);
	if	(file < 0)
	{
		error_msgs(errno, output_r->next->data);
		return (-5);
	}
	old_fd = 0;
	old_fd = dup(1);
	if (dup2(file, 1) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	return (old_fd);
}

int	input_r(t_datas *input_r)
{
	int file;
	int	old_fd;

	if (input_r->type == 7)
	{
		file = open(input_r->next->data, O_RDONLY, 000644);
		if	(file < 0)
		{
			error_msgs(errno, input_r->next->data);
			return (-5);
		}
	}
	else if (input_r->type == 33)
	{
		if (input_r->next->next && input_r->next->next->type == 39)
			input_r = input_r->next->next;
		//printf("data == %s --- heredoooooc %d\n", input_r->data, input_r->type);
		file = open(".hd2", O_TRUNC | O_CREAT | O_RDWR, 000666);
		if	(file < 0)
		{
			error_msgs(errno, input_r->next->data);
			return (-5);
		}
		write(file, input_r->data, ft_strlen(input_r->data));
		close(file);
		file = open(".hd2", O_RDONLY);
		if	(file < 0)
		{
			error_msgs(errno, input_r->next->data);
			return (-5);
		}
	}
	old_fd = dup(0);
	if	(dup2(file, STDIN_FILENO) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	return (file);
}

void	delete_node(t_flist **li)
{
	t_flist 	*list;
	t_datas		*stock_prev;
	t_datas		*stock_next;
	t_datas	*current;

	list = *li;
	//affiche(list->process);
	while(list)
	{
		current =  list->process->first;
		while(current)
		{
			if (current->data[0] == '\0')
			{
				if	(current->previous)
					stock_prev = current->previous;
				else
					stock_prev = NULL;
				while(current->data[0] == '\0')
				{
					if (current->next)
						current = current->next;
					else
						break ;
				}
				if	(!current->next)
				{
					stock_prev->next = NULL;
					break ;
				}
				else
				{
					stock_next = current;
					stock_prev->next = stock_next;
					stock_next->previous = stock_prev;
				}
			}
			if (current->next)
				current = current->next;
			else
				break ;
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
}

int	manage_redirections(t_flist **li)
{
	t_flist	*list;
	int	inp_redir;
	int	outp_redir;
	int	file;
	int	i;
	int	j;
	t_datas	*current;

	i = 0;
	j = 0;
	list = *li;
	file = 0;
	inp_redir = list->nb_heredoc + list->nb_lred;
	//printf("inp redir --> %d \n", inp_redir);
	outp_redir = list->nb_rred_app + list->nb_rred;
	current = list->process->first;
	while(current)
	{
		//printf("current->data %s \n", current->data);
		if	(current->type == 6 || current->type == 38)
		{
			i++;
			if	(i == outp_redir)
			{
				if	(output_r(current) == -5)
					return (-5);
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
			}
			else
			{
	
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
				else
					break ;
				
			}
		}
		else if	(current->type == 7 || current->type == 33)
		{
			if (current->type == 7 && current->next->type == 21)
			{
				if (open(current->next->data, O_RDONLY) == -1)
				{
					error_msgs(errno, current->next->data);
					return(-5) ;
				}
			}
			j++;
			if	(j == inp_redir)
			{
				//printf(" ---- current ->data %s \n", current->data);
				if(input_r(current) == -5)
					return (-5);
				//printf("fileuuuh = %d \n", file);
				current->data = ft_strdup("");
				if(current->next && (current->next->type == 21 || current->next->type == 35 
					|| current->next->type == 36 || current->next->type == 37))
					current->next->data = ft_strdup("");
				if (current->type == 33 && (current->next->next->type == 39))
					current->next->next->data = ft_strdup("");
			}
			else
			{
				current->data = ft_strdup("");
				if (current->next)
				{
					current = current->next;
					current->data = ft_strdup("");
				}	
				else
					break ;
				if (current->next->type == 39)
				{
					current->next->data = ft_strdup("");
				}
			}
		}
		if (current->next)
		{
			current = current->next;
		}
		else
			break ;
	}
	delete_node(&list);
	//affiche(list->process);
	return (file);
}