#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	manage_redir(t_dblist *list)
{
	t_dblist	*head;
	int		file;
	char	*buf;

	head = list;
	file = open("file", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	while (1)
    {
        write(1, '>', 1);
		buf = get_next_line(0);
        if (buf == NULL)
            exit(1);
		while(head->first)
		{

			if (head->first->type == 33 || head->first->type == 34)
			{
				head->first = head->first->next;
				break ;
			}
			head = head->first->next;
		}
        if (!ft_strncmp(head->first->data, buf, ft_strlen(head->first->data) + 1))
            break ;
        write(file, buf, ft_strlen(buf));
        write(file, "\n", 1);
        free(buf);
	}
}