#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	manage_one_redir(t_datas *delimiter)
{
	t_datas	*copy;
	int		file;
	char	*buf;

	copy = delimiter;
	file = open("file", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	while (1)
    {
        write(1, ">", 2);
		buf = get_next_line(0);
        if (buf == NULL)
            exit(1);
		while(copy)
		{

			if (copy->type == 33 || copy->type == 34)
			{
				copy = copy->next;
				break ;
			}
			copy = copy->next;
		}
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data) + 1))
            break ;
        write(file, buf, ft_strlen(buf));
        write(file, "\n", 1);
        free(buf);
	}
}