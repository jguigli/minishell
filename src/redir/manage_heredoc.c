#include "../../includes/minishell.h"
#include "../../libft/libft.h"

char	*manage_one_redir(t_datas *delimiter, t_flist *gr_list)
{
	t_datas	*copy;
	int		file;
	char	*buf;
	char	*str_to_get;
	char	*tmp;
	int	old_fd;


	copy = delimiter;
	str_to_get = NULL;
	tmp = NULL;
	//if (gr_list->nb_heredoc == 1)
	file = open("infile", O_TRUNC | O_CREAT | O_RDWR , 0000644);
	//if (gr_list->nb_heredoc > 1)
		//file = open("infile", O_CREAT | O_RDWR | O_APPEND, 0000644);
	if (file < 0)
		error_msgs();
	while (1)
    {
        write(1, "> ", 3);
		buf = get_next_line(0);
		// quand saisie == NUll, le prg beugue ==> voir gnl et utils
        if (buf == NULL)
            buf = ft_strdup("");
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
		{
			if (gr_list->nb_heredoc > 1)
			{
				write(file, buf, ft_strlen(buf));
				//write(file, "\n", 2);
				free(buf);
			}
            break ;
		}
        write(file, buf, ft_strlen(buf));
        //write(file, "\n", 2);
        free(buf);
	}
	close(file);
	return (NULL);
}

// int	manage_multiple_redir(t_datas *delimiter, t_flist **gen_list)
// {
// 	t_datas	*copy;
// 	//t_datas	*copy2;
// 	t_flist	*head;
// 	t_datas	*head2;
// 	int		file;
// 	char	*buf;
// 	char	*tmp;
// 	char	*str_to_get;
// 	int		fi;
// 	int		i;
// 	int		j;
// 	int		wstatus;

// 	j = 0;
// 	copy = delimiter;
// 	head = *gen_list;
// 	head2 = (*gen_list)->process->first;
// 	str_to_get = NULL;
// 	tmp = NULL;
// 	i = 0;
// 	while(i < head->nb_heredoc)
// 	{
// 		//printf("copy->data here == %s\n", copy->data);
// 		file = open("infile2", O_CREAT | O_RDWR  | O_APPEND , 0000644);
// 		fi =  fork();
// 		//printf("%d\n", fi);
// 		if (fi < 0)
// 			error_msgs();
// 		if (fi == 0)
// 		{
// 			while (1)
// 			{
// 				write(1, "> ", 3);
// 				buf = get_next_line(0);
// 				//printf("BUF == %s\n", buf);
// 				if (buf == NULL)
// 					exit(1);
// 				if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
// 				{
// 					j++;
// 					write(file, buf, ft_strlen(buf));
// 					free(buf);
// 					if (copy->next)
// 						copy = copy->next;
// 					else 
// 						return (0);
// 					while (copy && (copy->type != 35 && copy->type != 36 && copy->type != 37))
// 					{
// 						if (copy->next)
// 							copy = copy->next;
// 						else 
// 							break ;
// 					}
// 					if (j == head->nb_heredoc)
// 						return (0);
// 					// //printf("copy->data = %s\n", copy->data);
// 					// close(file);
// 					// file = open("infile2", O_RDONLY);
// 					// //printf("fd file ==> %d\n", file);
// 					// tmp = get_next_line(file);
// 					// //printf("tmp ==> %s\n", tmp);
// 					// while (tmp != NULL)
// 					// {
// 					// 	//printf("tmp ==> %s\n", tmp);
// 					// 	str_to_get = ft_strjoin(str_to_get, tmp);
// 					// 	free(tmp);
// 					// 	tmp = get_next_line(file);	
// 					// }
// 					// //printf("str to get ==> %s\n", str_to_get);
// 					// close(file);
// 					// insert_node(copy, str_to_get, gen_list);
// 					// str_to_get = NULL;
// 					// free(str_to_get);
// 					// free(tmp);
// 					// //affiche((*gen_list)->process);
// 					// if (j == head->nb_heredoc)
// 					// 	return (0);
// 					// break ;
// 				}
// 				write(file, buf, ft_strlen(buf));
// 				free(buf);
// 			}
// 		}
// 	}
// 	close(file);
// 	return (0);
// }