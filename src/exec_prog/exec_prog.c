#include "../../includes/minishell.h"

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
	if (pipe)
	{
		exec_complex_cmd(list, env);
	}
	else
		exec_simple_cmd(list, env);
	return (1);
}