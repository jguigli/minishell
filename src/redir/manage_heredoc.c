#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	count_quote(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (argv[i] == 39 || argv[i] == 34)
			count++;
		i++;
	}
	return (count);
}

char	*hd_removedquote(char *str)
{
	int	i;
	int	j;
	char	*temp;
	char	*rep;

	i = 0;
	j = 0; 
	rep = ft_strdup("");
	while(str[i])
	{
		j = i;
		while (str[i] != 34 && str[i] != 39 && str[i])
			i++;
		if (i != j)
		{
			temp = ft_substr(str, j, i - j);
			rep = ft_strjoin(rep, temp);
		}
		if (str[i] == '\"')
		{
			i++;
			j = i;
			while (str[i] != '\"' && str[i])
				i++;
			temp = ft_substr(str, j, i - j);
			rep = ft_strjoin(rep, temp);
			free(temp);
		}
		else if (str[i] == '\'')
		{
			i++;
			j = i;
			while (str[i] != '\'' && str[i])
				i++;
			temp = ft_substr(str, j, i - j);
			rep = ft_strjoin(rep, temp);
			free(temp);
		}
	}
	free (str);
	return (rep);
}

char	*hd_expansion(char *str)
{
	int	i;
	int j;
	char	*temp;
	char	*rep;

	i = 0;
	j = 0;
	rep = ft_strdup("");
	while (str[i])
	{
		j = i;
		while (str[i] != '$' && str[i])
			i++;
		if (i != j)
		{
			temp = ft_substr(str, j, i - j);
			rep = ft_strjoin(rep, temp);
		}
		if (str[i] == '$')
		{
			i++;
			j = i;
			while (ft_isalnum(str[i]) && str[i])
				i++;
			temp = ft_substr(str, j, i - j);
			//temp = search_in_env_var(temp, env); // A DECOMMENTER
			if (temp)
				rep = ft_strjoin(rep, temp);
		}
	}
	return (rep);
}

void	manage_one_redir(t_datas *delimiter, t_flist *gr_list, pid_t pid)
{
	t_datas	*copy;
	int		file;
	char	*buf;
	char	*str_to_get;
	char	*tmp;
	__sighandler_t 	sigos;
	int		ctrl;

	//manage_signal_hd();
	copy = delimiter;
	str_to_get = NULL;
	tmp = NULL;
	ctrl = 0;
	//affiche(gr_list->process);
	if (copy->type == 35)
	{
		if (!count_quote(copy->data))
		{
			//printf("testttt 1 -- %s\n", copy->data);
			copy->expansion = 1;
		}
		else
		{
			//printf("testttt 2 -- %s\n", copy->data);
			copy->data = hd_removedquote(copy->data);
		}
		//printf("quand y a pas de quote = %s\n", copy->data);
	}
	else if (copy->type == 36 || copy->type == 37)//double quoted
	{
		//printf("testttt 2\n");
		copy->data = hd_removedquote(copy->data);
		//printf("quand y a des quote = %s\n", copy->data);
	}
	file = open(".hd1", O_TRUNC | O_CREAT | O_RDWR , 0000644);
	if (file < 0)
	{
		error_msgs(errno, ".hd1");
		exit(status);
	}
	while (1)
    {
		write(1, "> ", 3);
		buf = get_next_line(0);
		if (gr_list->process->infos->get_chr_c[buf[0]] == CHR_EOF)
		{
			printf("papaaaa \n");
			free(buf);
			break ;
		}
		if (!buf[0])
			break ;
		if (copy->expansion)
			buf = hd_expansion(buf);
		if (!ft_strncmp(copy->data, buf, ft_strlen(copy->data)))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	close(file);
	exit(status);
}

