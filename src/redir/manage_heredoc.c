#include "../../includes/minishell.h"
#include "../../gnl/get_next_line.h"
#include "../../libft/libft.h"

int	manage_one_redir(t_datas *delimiter)
{
	t_datas	*copy;
	int		file;
	char	*buf;
	char	*test;
	int	old_fd;


	copy = delimiter;
	file = open("infile", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	while (1)
    {
        write(1, "> ", 3);
		buf = get_next_line(0);
		//printf("length copy->data : %ld --- length : buf == %ld\n", ft_strlen(copy->data), ft_strlen(buf));
        if (buf == NULL)
            exit(1);
		//printf("comparaison %d \n", ft_strncmp(copy->data, buf, ft_strlen(copy->data)));
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
            break ;
        write(file, buf, ft_strlen(buf));
        //write(file, "\n", 2);
        free(buf);
	}
	old_fd = dup(0);
	dup2(file, STDIN_FILENO);
	dup2(old_fd, STDIN_FILENO);
	close(file);
	close(old_fd);
	return (0);
}

int	manage_multiple_redir(t_datas *delimiter, t_flist **gen_list)
{
	t_datas	*copy;
	//t_datas	*copy2;
	t_flist	*head;
	t_datas	*head2;
	int		file;
	char	*buf;
	char	*test;
	int		i;
	int		j;

	j = 0;
	//copy2 = delimiter;
	copy = delimiter;
	head = *gen_list;
	head2 = (*gen_list)->process->first;
	// while (head2)
	// {
	// 	if (head2->type == 35 || head2->type == 36 || head2->type == 37)
	// 		j++;
	// 	if (j == head->nb_heredoc)
	// }
	i = 0;
	file = open("infile2", O_CREAT | O_RDWR, 0000644);
	while (1)
    {
        write(1, "> ", 3);
		buf = get_next_line(0);
		//printf("length copy->data : %ld --- length : buf == %ld\n", ft_strlen(copy->data), ft_strlen(buf));
        if (buf == NULL)
            exit(1);
		//printf("comparaison %d \n", ft_strncmp(copy->data, buf, ft_strlen(copy->data)));
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
		{
			printf("%s\n", copy->data);
			if (copy->next)
			{
				copy = copy->next;
				printf("Ici = %s\n", copy->data);
			}
			else 
				return (0);
			while (copy && (copy->type != 35 && copy->type != 36 && copy->type != 37))
			{
				if (copy->next)
					copy = copy->next;
				else 
					break ;
			}
            //printf(" function multiple redir %s \n", copy->data);
		}

		
        write(file, buf, ft_strlen(buf));
		//test = get_next_line(file);
		//printf("%s \n", test);
        //write(file, "\n", 2);
        free(buf);
	}
}