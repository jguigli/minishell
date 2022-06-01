#include "../../includes/minishell.h"
#include "../../gnl/get_next_line.h"
#include "../../libft/libft.h"

char	*manage_one_redir(t_datas *delimiter)
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
	file = open("infile", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	while (1)
    {
        write(1, "> ", 3);
		buf = get_next_line(0);
        if (buf == NULL)
            exit(1);
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
            break ;
        write(file, buf, ft_strlen(buf));
        //write(file, "\n", 2);
        free(buf);
	}
	close(file);
	file = open("infile", O_RDONLY);
	//printf("fd file ==> %d\n", file);
	tmp = get_next_line(file);
	//printf("tmp ==> %s\n", tmp);
	while (tmp != NULL)
	{
		//printf("tmp ==> %s\n", tmp);
		str_to_get = ft_strjoin(str_to_get, tmp);
		//printf("str to get ==> %s\n", str_to_get);
		free(tmp);
		tmp = get_next_line(file);	
	}
	close(file);
	//printf("str_to_get %s\n", str_to_get);
	return (str_to_get);
}

int	manage_multiple_redir(t_datas *delimiter, t_flist **gen_list)
{
	t_datas	*copy;
	//t_datas	*copy2;
	t_flist	*head;
	t_datas	*head2;
	int		file;
	char	*buf;
	char	*tmp;
	char	*str_to_get;
	int		fi;
	int		i;
	int		j;
	int		wstatus;

	j = 0;
	copy = delimiter;
	head = *gen_list;
	head2 = (*gen_list)->process->first;
	str_to_get = NULL;
	tmp = NULL;
	i = 0;
	while(i < head->nb_heredoc)
	{
		//printf("copy->data here == %s\n", copy->data);
		file = open("infile2", O_TRUNC | O_CREAT | O_RDWR, 0000644);
		fi =  fork();
		//printf("%d\n", fi);
		if (fi < 0)
			error_msgs();
		if (fi == 0)
		{
			while (1)
			{
				write(1, "> ", 3);
				buf = get_next_line(0);
				//printf("BUF == %s\n", buf);
				if (buf == NULL)
					exit(1);
				if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
				{
					j++;
					//printf("copy->data = %s\n", copy->data);
					close(file);
					file = open("infile2", O_RDONLY);
					//printf("fd file ==> %d\n", file);
					tmp = get_next_line(file);
					//printf("tmp ==> %s\n", tmp);
					while (tmp != NULL)
					{
						//printf("tmp ==> %s\n", tmp);
						str_to_get = ft_strjoin(str_to_get, tmp);
						free(tmp);
						tmp = get_next_line(file);	
					}
					//printf("str to get ==> %s\n", str_to_get);
					close(file);
					insert_node(copy, str_to_get, gen_list);
					str_to_get = NULL;
					free(str_to_get);
					free(tmp);
					//affiche((*gen_list)->process);
					if (j == head->nb_heredoc)
						return (0);
					break ;
				}
				write(file, buf, ft_strlen(buf));
				free(buf);
			}
		}
		//printf("wait pid %d \n", waitpid(fi, &wstatus, 0));
		waitpid(fi, &wstatus, 0);
		if (WIFEXITED (wstatus))
			return (WEXITSTATUS(wstatus));
		copy = copy->next;
		while (copy && (copy->type != 35 && copy->type != 36 && copy->type != 37))
		{
			if (copy->next)
				copy = copy->next;
			else
				break ;
		}
		//printf("copy avant boucle  %s -- %d\n", copy->data, copy->type);	
		i++;
	}
	close(file);
	return (0);
}