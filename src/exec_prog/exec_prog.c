#include "../../includes/minishell.h"

int		is_builtin(char *cmd)
{
	int	i;
	char	*builtin[] = {"cd", "echo", "env", "exit", "export", "pwd", "unset", NULL};

	i = 0;
	while (builtin[i])
	{
		if (!strcmp(builtin[i], cmd))
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(char **arg, char **env)
{
	if (!strcmp(arg[0], "cd"))
		ft_cd(arg, env);
	else if (!strcmp(arg[0], "echo"))
		ft_echo(arg);
	else if (!strcmp(arg[0], "env"))
		ft_env(arg, env);
	else if (!strcmp(arg[0], "exit"))
		ft_exit(arg);
	else if (!strcmp(arg[0], "export"))
		ft_export(arg, env);
	else if (!strcmp(arg[0], "pwd"))
		ft_pwd(arg);
	else if (!strcmp(arg[0], "unset"))
		ft_unset(arg, env);
	return ;
}

char	**list_to_tab(t_dblist *list)
{
	char	**tab;
	int		size;
	int		i;
	t_datas *current;

	i = 0;
	current = list->first;
	size = my_lstsize_dblist(list);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		exit(0);
	while (current)
	{
		tab[i] = ft_strdup(current->data);
		current = current->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	exec_launcher(t_flist **li, char **env)
{
	int	pipe;
	t_flist	*list;
	t_flist	*list2;

	list = *li;
	list2 = *li;
	pipe = my_lstsize(&list) - 1;
	if (pipe > 0)
	{
		//printf("OKKKKK geuuuurl \n");
		exec_complex_cmd(list, env);
	}
	else if	(pipe == 0)
	{
		if (exec_simple_cmd(list, env) == 10)
		{
			exit(g.status);

		}
	}
	return (1);
}