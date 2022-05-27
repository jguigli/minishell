#include "../../includes/minishell.h"
#include "../../gnl/get_next_line.h"
#include "../../libft/libft.h"

int	manage_one_redir(t_datas *delimiter)
{
	t_datas	*copy;
	int		file;
	char	*buf;
	char	*test;


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
        write(file, "\n", 2);
        free(buf);
	}
}

int	manage_multiple_redir(t_datas *delimiter, t_flist **gen_list)
{
	t_datas	*copy;
	t_flist	*head;
	int		file;
	char	*buf;
	char	*test;
	int		i;


	copy = delimiter;
	head = *gen_list;
	i = 0;
	file = open("infile2", O_TRUNC | O_CREAT | O_RDWR, 0000644);
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
			if (copy->next)
				copy = copy->next;
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
        write(file, "\n", 2);
        free(buf);
	}
}