#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, t_flist *list, char **envp)
{
	manage_redirections(&list);
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(0);
	if (is_builtin(exec.cmd_arg[0]))
		exec_builtin(exec.cmd_arg, envp);
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd)
			exit(0);
		if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
			exit(0);
	}
}

int	output_r(t_datas *output_r)
{
	int file;
	int	old_fd;

	file = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	if	(file < 0)
		error_msgs();
	old_fd = 0;
	old_fd = dup(1);
	dup2(file, 1);
	return (file);
}

int	input_r(t_datas *input_r)
{
	int file;
	int	old_fd;

	file = open(input_r->next->data, O_RDONLY, 000644);
	if	(file < 0)
		error_msgs();
	old_fd = dup(0);
	dup2(file, STDIN_FILENO);
	return (file);
}

void	delete_node(t_flist **li)
{
	t_flist 	*list;
	t_datas		*stock_prev;
	t_datas		*stock_next;
	t_datas	*current;

	list = *li;
	//affiche(list->process);
	while(list)
	{
		current =  list->process->first;
		while(current)
		{
			printf("data heeeeeeeeeeeeere %s\n", current->data);
			if (current->data[0] == '\0')
			{
				if	(current->previous)
					stock_prev = current->previous;
				else
					stock_prev = NULL;
				while(current->data[0] == '\0')
				{
					if (current->next)
						current = current->next;
					else
						break ;
				}
				if	(!current->next)
				{
					stock_prev->next = NULL;
					break ;
				}
				else
				{
					stock_next = current;
					stock_prev->next = stock_next;
					stock_next->previous = stock_prev;
				}
			}
			if (current->next)
				current = current->next;
			else
				break ;
		}
		//current->next = NULL;
		if (list->next)
			list = list->next;
		else
			break ;
	}
	//affiche(list->process);
}

int	manage_redirections(t_flist **li)
{
	t_flist	*list;
	int	inp_redir;
	int	outp_redir;
	int	file;
	int	i;
	int	j;
	t_datas	*current;

	i = 0;
	j = 0;
	list = *li;
	file = 0;
	inp_redir = list->nb_heredoc + list->nb_lred;
	outp_redir = list->nb_rred_app + list->nb_rred;
	current = list->process->first;
	//saffiche(list->process);
	while(current)
	{
		if	(current->type == 6 || current->type == 38)
		{
			i++;
			if	(i == outp_redir)
			{
				file = output_r(current);
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
				break ;
			}
			else
			{
	
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
				else
					break ;
				
			}
		}
		else if	(current->type == 7 || current->type == 33)
		{
			j++;
			if	(j == inp_redir)
			{
				file = input_r(current);
				current->data = ft_strdup("");
				if(current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
				break ;
			}
			else
			{
				current->data = ft_strdup("");
				if (current->next)
					current->next->data = ft_strdup("");
				else
					break ;
				if (current->type == 33 && (current->next->next->type == 39))
					current->next->next->data = ft_strdup("");
			}
		}
		if (current->next)
			current = current->next;
		else
			break ;
	}
	delete_node(&list);
	//affiche(list->process);
	return (file);
}

void	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;
	int		file;

	shell_parameter_expansion(list->process, env);
	//file = manage_redirections(&list);
	//affiche(list->process);
	//printf("file == %d \n", file);
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	// arg = list_to_tab(list->process);
	exec.pid = fork();;
	if (exec.pid == -1)
		exit(0);
	else if (!exec.pid)
		child_process_simple(exec, list, env);
	//close(file);
	free(arg);
	waitpid(exec.pid, NULL, 0);
}