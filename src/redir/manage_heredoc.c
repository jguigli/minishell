#include "../../includes/minishell.h"
#include "../../libft/libft.h"

// static int	count_quote(char *argv)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (argv[++i])
// 	{
// 		if (argv[i] == 39)
// 			count++;
// 	}
// 	return (count);
// }

char	*manage_one_redir(t_datas *delimiter, t_flist *gr_list)
{
	t_datas	*copy;
	int		file;
	int		quote;
	char	*buf;
	char	*str_to_get;
	char	*tmp;
	int	old_fd;


	copy = delimiter;
	str_to_get = NULL;
	tmp = NULL;
	// if (copy->type == 36)
	// {

	// }
	// else if (copy->type == 37)
	// {

	// }
	// else if (copy->type == 38)
	// {

	// }
	file = open(".hd1", O_TRUNC | O_CREAT | O_RDWR , 0000644);
	if (file < 0)
	{
		error_msgs(errno, ".hd1");
		return (-200);
	}
	while (1)
    {
        write(1, "> ", 3);
		buf = get_next_line(0);
        if (buf == NULL)
            break ;
		// if (copy->type == 36)
		// {
		// 	//expand
		// }
        if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
            break ;
        write(file, buf, ft_strlen(buf));
        free(buf);
	}
	close(file);
	return (NULL);
}

