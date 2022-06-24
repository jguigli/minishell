#include "../../includes/minishell.h"

int	output_r(t_datas *output_r, t_main *main)
{
	if	(output_r->type == 6)
	{
		main->my_fds[0] = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	}
	if	(output_r->type == 38)
		main->my_fds[0] = open(output_r->next->data, O_CREAT | O_RDWR | O_APPEND, 000644);
	//printf("tableau de fd, fd[0] == %d\n", main->my_fds[0]);
	if	(main->my_fds[0] < 0)
	{
		error_msgs(errno, output_r->next->data);
		printf("D --- here\n");
		return (-5);
	}
	main->my_oldfds[0] = dup(STDOUT_FILENO);
	if (dup2(main->my_fds[0], STDOUT_FILENO) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	//close(main->my_fds[0]);
	// close(3);
	// dup2(main->my_oldfds[0], STDOUT_FILENO);
	// close(main->my_oldfds[0]);
	return (0);
}

int	input_r(t_datas *input_r, t_main *main)
{

	if (input_r->type == 7)
	{
		main->my_fds[1] = open(input_r->next->data, O_RDONLY, 000644);
		if	(main->my_fds[1] < 0)
		{
			error_msgs(errno, input_r->next->data);
			printf("E --- here\n");
			return (-5);
		}
	}
	else if (input_r->type == 33)
	{
		if (input_r->next->next && input_r->next->next->type == 39)
			input_r = input_r->next->next;
		//printf("data == %s --- heredoooooc %d\n", input_r->data, input_r->type);
		main->my_fds[1] = open(".hd2", O_TRUNC | O_CREAT | O_RDWR, 000644);
		if	(main->my_fds[1] < 0)
		{
			error_msgs(errno, input_r->next->data);
			printf("teest\n");
			return (-5);
		}
		write(main->my_fds[1], input_r->data, ft_strlen(input_r->data) + 1);
		close(main->my_fds[1]);
		main->my_fds[1] = open(".hd2", O_RDONLY);
		if	(main->my_fds[1] < 0)
		{
			error_msgs(errno, input_r->next->data);
			printf("F --- here\n");
			return (-5);
		}
		//close(main->my_fds[1]);
	}
	main->my_oldfds[1] = dup(0);
	if	(dup2(main->my_fds[1], STDIN_FILENO) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	return (main->my_fds[1]);
}

void	delete_node(t_flist **li)
{
	t_flist 	*list;
	t_datas		*stock_prev;
	t_datas		*stock_next;
	t_datas		*stock_curr;
	t_datas		*current;

	list = *li;
	//affiche(list->process);
	while(list)
	{
		current = list->process->first;
		while(current && current->data[0] == '\0')
		{
			stock_curr = current;
			current = current->next;
			free(stock_curr);
		}
		list->process->first = current;
		//fprintf(stderr, "A --- current->data %s --- \n", list->process->first->data);
		if	(current->next)
			current = current->next;
		else
			break ;
		while(current)
		{
			if (current && current->data[0] != '\0')
			{
				current = current->next;
			}
			else
			{
				if (current->next)
				{
					//fprintf(stderr, "B -- current->data %s --- current type == %d\n", current->data, current->type);
					stock_next = current->next;
					//fprintf(stderr, "C --- current->data %s --- current type == %d\n", stock_next->data, stock_next->type);
					stock_curr = current;
					stock_prev = current->previous;
					//fprintf(stderr, "D --- current->data %s --- current type == %d\n", stock_prev->data, stock_prev->type);
					current = current->next;
					free (stock_curr);
					stock_prev->next = stock_next;
					stock_next->previous = stock_prev;
				}
				else if (current->next == NULL)
				{
					//fprintf(stderr, "E --- current->data %s --- current type == %d\n", current->data, current->type);
					stock_prev = current->previous;
					//fprintf(stderr, " F --- current->data %s --- current type == %d\n", stock_prev->data, stock_prev->type);
					stock_prev->next = NULL;
					//stock_curr = current;
					free (current);
					break ;
					//stock_next->previous = stock_prev;
				}
			}
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
	//affiche(list->process);
}


int	manage_redirections(t_flist **li, t_main *main)
{
	t_flist	*list;
	int	inp_redir;
	int	outp_redir;
	int	i;
	int	j;
	t_datas	*current;

	i = 0;
	j = 0;
	list = *li;
	//affiche(list->process);
	inp_redir = list->nb_heredoc + list->nb_lred;
	outp_redir = list->nb_rred_app + list->nb_rred;
	//printf("inp redir --> %d --  output redir == %d\n", inp_redir, outp_redir);
	current = list->process->first;
	while(current)
	{
		//printf("current->data %s \n", current->data);
		if	(current->type == 6 || current->type == 38)
		{
			i++;
			if	(i == outp_redir)
			{
				//printf("herre i = %d === outp_redir = %d -- data == %s\n", i, outp_redir, current->data);
				//printf("maaaaaiiiin EDBUTN  == %d\n", main->my_fds[0]);
				if	(output_r(current, main) == -5)
				{
					printf("C --- here????\n");
					return (-5);
				}
				//close(main->my_fds[0]);
				//printf("maaaaaiiiin FIN  == %d\n", main->my_fds[0]);
				//printf("data = %s --- next data == %s\n", current->data, current->next->data);
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
				{
					current = current->next;
					current->data = ft_strdup("");
				}
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
					//printf("A -- here????\n");
					return(-5) ;
				}
			}
			j++;
			if	(j == inp_redir)
			{
				//printf("hey -- current data %s\n", current->data);
				if(input_r(current, main) == -5)
				{
					//printf("B --- here????\n");
					return (-5);
				}
				//printf("Sortie : current->data %s \n", current->next->data);
				//printf("fileuuuh = %d \n", file);
				//printf(" A ---- current ->data %s --- current type : %d\n", current->data, current->type);
				current->data = ft_strdup("");
				if(current->next && (current->next->type == 21 || current->next->type == 35 
					|| current->next->type == 36 || current->next->type == 37))
				{
					//printf(" B ---- current ->data %s --- current type : %d\n", current->data, current->type);
					current =  current->next;
					current->data = ft_strdup("");
				}
				if (current->next && current->next->type == 39)
				{
					current = current->next;
					current->data = ft_strdup("");
				}
				//affiche(list->process);
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
				if (current->next && current->next->type == 39)
				{
					current = current->next;
					current->data = ft_strdup("");
				}
			}
			//delete_node(&list);
		}
		//printf("CURRREEENT == %s\n", current->data);
		if (current->next)
		{
			current = current->next;
			//printf("dataaaa %s\n", current->data);
		}
		else
			break ;
	}
	// affiche(list->process);
	delete_node(&list);
	return (0);
}