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

