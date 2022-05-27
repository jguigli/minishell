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
	file = open("file", O_TRUNC | O_CREAT | O_RDWR, 0000644);
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