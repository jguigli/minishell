#include "../../includes/minishell.h"

static int	ft_strchrr(const char *s, int c)
{
    char            *sent;
    unsigned char    character;
    size_t            i;

    sent = (char*)s;
    character = (unsigned char)c;
    i = 1;
    while (i <= ft_strlen(s))
    {
        if (sent[i] == character)
		{
			//printf("character %c\n", sent[i]);
            return (2);
		}
        i++;
    }
    return (0);
}

int	parse_cmd(char *argument)
{
	if (argument[0] == '/')
		return (-1);
	else if (ft_strchrr(argument, '/') == 2)
		return (-1);
	else if (ft_strchrr(argument, '.') != 0)
		return (-1);
	else
		return (0);
}

char	*get_command(char **path, char *cmd)
{
	char	*temp;
	char	*path_cmd;
	int		i;

	i = 0;
	path_cmd = NULL;
	if (!cmd)
		return (NULL);
	if (!path)
		return (cmd);
	if (parse_cmd(cmd) == -1)
	{
		if	(access(cmd, F_OK) == 0)
		{
			write(1, "OKKK\n", 6);
			return (cmd);
		}
		else
			return ("KO");
	}
	else 
	{
		while (path[i])
		{
			if (cmd[0] == '/')
				return (NULL);
			temp = ft_strjoin_path(path[i], "/");
			path_cmd = ft_strjoin(temp, cmd);
			if (access(path_cmd, 0) == 0)
				return (path_cmd);
			free(path_cmd);
			i++;
		}

	}
	return (NULL);
}
