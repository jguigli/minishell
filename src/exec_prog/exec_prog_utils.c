/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:17:42 by ael-khat          #+#    #+#             */
/*   Updated: 2022/07/20 12:17:43 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strchrr(const char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 1;
	while (i <= ft_strlen(s))
	{
		if (sent[i] == character)
			return (2);
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
	else if (ft_strnstr(argument, "./", ft_strlen(argument)) != NULL)
		return (-1);
	else if (ft_strnstr(argument, "..", ft_strlen(argument)) != NULL)
		return (-1);
	else
		return (0);
}

static char	*get_command_path(char **path, char *cmd)
{
	int		i;
	char	*temp;
	char	*path_cmd;

	i = 0;
	path_cmd = NULL;
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
	return (NULL);
}

char	*get_command(char **path, char *cmd)
{
	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (!path)
		return (ft_strdup("KO"));
	if (parse_cmd(cmd) == -1)
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (ft_strdup("KO"));
	}
	else
		return (get_command_path(path, cmd));
}

void	cc_errors(char *cmd, t_exec_c *exec)
{
	if (ft_strcmp(cmd, "..") == 0)
		freeing_cmd_c(exec);
	else if (ft_strlen(cmd) == 17
		&& ft_strcmp(cmd, "/usr/local/sbin/.") == 0)
	{
		syntax_err("filename argument required", cmd);
		printf("%s: usage: %s filename [arguments]\n", cmd, cmd);
		g_status = 2;
	}
	else if (ft_strchrr(cmd, '/') == 2 && !check_stat(exec->cmd))
	{
		isdir_err(DIR_ERR, cmd);
		g_status = 126;
	}
	else
	{
		error_msgs(errno, cmd);
		g_status = 126;
	}
}
