#include "../../includes/minishell.h"

int	output_r(t_datas *output_r)
{
	if	(output_r->type == 6)
		g.my_fds[0] = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	if	(output_r->type == 38)
		g.my_fds[0] = open(output_r->next->data, O_CREAT | O_RDWR | O_APPEND, 000644);
	if	(g.my_fds[0] < 0)
	{
		error_msgs(errno, output_r->next->data);
		printf("D --- here\n");
		return (-5);
	}
	g.my_oldfds[0] = dup(STDOUT_FILENO);
	if (dup2(g.my_fds[0], STDOUT_FILENO) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	return (g.my_oldfds[0]);
}

int	input_r(t_datas *input_r)
{

	if (input_r->type == 7)
	{
		g.my_fds[1] = open(input_r->next->data, O_RDONLY, 000644);
		if	(g.my_fds[1] < 0)
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
		g.my_fds[1] = open(".hd2", O_TRUNC | O_CREAT | O_RDWR, 000644);
		if	(g.my_fds[1] < 0)
		{
			error_msgs(errno, input_r->next->data);
			printf("teest\n");
			return (-5);
		}
		write(g.my_fds[1], input_r->data, ft_strlen(input_r->data) + 1);
		close(g.my_fds[1]);
		g.my_fds[1] = open(".hd2", O_RDONLY);
		if	(g.my_fds[1] < 0)
		{
			error_msgs(errno, input_r->next->data);
			printf("F --- here\n");
			return (-5);
		}
		//close(g.my_fds[1]);
	}
	g.my_oldfds[1] = dup(0);
	if	(dup2(g.my_fds[1], STDIN_FILENO) == -1)
	{
		error_msgs(errno, "Fd's duplication failed");
		return (-5);
	}
	return (g.my_fds[1]);
}

// t_datas	*delete_node(t_flist **li)
// {
// 	t_flist 	*list;
// 	t_flist 	*list2;
// 	t_datas		*stock_prev;
// 	t_datas		*stock_next;
// 	t_datas		*current;
// 	t_datas		*head;

// 	list = *li;
// 	list2 = *li;
// 	//affiche(list->process);
// 	// stock_prev = NULL;
// 	// stock_next = NULL;
// 	// while(list)
// 	// {
// 	// 	current =  list->process->first;
// 	// 	head  = list->process->first;
// 	// 	while(current)
// 	// 	{
// 	// 		while(current->data[0] == '\0')
// 	// 		{
// 	// 			fprintf(stderr, "Heyyyy --> %d\n", current->type);
// 	// 			if (current == NULL)
// 	// 			{
// 	// 				//affiche(list2->process);
// 	// 				return (head);

// 	// 			}
// 	// 			current = current->next;
// 	// 		}
// 	// 		head = current;
// 	// 		list2->process->first = head;
// 	// 		current = current->next;
// 	// 		while(current != NULL && current->data[0] != '\0')
// 	// 		{
// 	// 			stock_prev = current;
// 	// 			current = current->next;
// 	// 			stock_next = current;
// 	// 		}
// 	// 		stock_next = current->next;
// 	// 	}
// 	// 	if (list->next)
// 	// 		list = list->next;
// 	// 	else
// 	// 		break ;
// 	// }
// 		while(list)
// 	{
// 		current =  list->process->first;
// 		while(current)
// 		{
// 			if (current->data[0] == '\0')
// 			{
// 				if	(current->previous)
// 					stock_prev = current->previous;
// 				else
// 					stock_prev = NULL;
// 				while(current->data[0] == '\0')
// 				{
// 					if (current->next)
// 						current = current->next;
// 					else
// 						break ;
// 				}
// 				if	(!current->next)
// 				{
// 					stock_prev->next = NULL;
// 					break ;
// 				}
// 				else
// 				{
// 					stock_next = current;
// 					stock_prev->next = stock_next;
// 					stock_next->previous = stock_prev;
// 				}
// 			}
// 			if (current->next)
// 				current = current->next;
// 			else
// 				break ;
// 		}
// 		if (list->next)
// 			list = list->next;
// 		else
// 			break ;
// 	}
// }

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
		//fprintf(stderr, "A --- current->data %s --- current type == %d\n", current->data, current->type);
		current = current->next;
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
	//affiche(list->process);
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
				//printf("herre i = %d === outp_redir = %d -- data == %s\n", i, outp_redir, current->data);
				if	(output_r(current) == -5)
				{
					//printf("C --- here????\n");
					return (-5);
				}
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
				if(input_r(current) == -5)
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
	//affiche(list->process);
	delete_node(&list);
	return (file);
}