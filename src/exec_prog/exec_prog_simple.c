#include "../../includes/minishell.h"

int	output_r(t_datas *output_r)
{
	int file;
	int	old_fd;

	if	(output_r->type == 6)
		file = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	if	(output_r->type == 38)
		file = open(output_r->next->data, O_CREAT | O_RDWR | O_APPEND, 000644);
	if	(file < 0)
	{
		printf("11111 \n");
		error_msgs();
	}
	old_fd = 0;
	old_fd = dup(1);
	dup2(file, 1);
	return (old_fd);
}

int	input_r(t_datas *input_r)
{
	int file;
	int	old_fd;

	if (input_r->type == 7)
	{
		file = open(input_r->next->data, O_RDONLY, 000644);
		if	(file < 0)
		{
			printf("2222 \n");
			error_msgs();
		}
	}
	else if (input_r->type == 33)
	{
		if (input_r->next->next && input_r->next->next->type == 39)
			input_r = input_r->next->next;
		//printf("data == %s --- heredoooooc %d\n", input_r->data, input_r->type);
		file = open(".hd2", O_TRUNC | O_CREAT | O_RDWR, 000666);
		write(file, input_r->data, ft_strlen(input_r->data));
		close(file);
		file = open(".hd2", O_RDONLY);
	}
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
		if (list->next)
			list = list->next;
		else
			break ;
	}
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
	//printf("inp redir --> %d \n", inp_redir);
	outp_redir = list->nb_rred_app + list->nb_rred;
	current = list->process->first;
	while(current)
	{
		//printf("current->data %s \n", current->data);
		if	(current->type == 6 || current->type == 38)
		{
			i++;
			if	(i == outp_redir)
			{
				file = output_r(current);
				current->data = ft_strdup("");
				if (current->next && current->next->type == 21)
					current->next->data = ft_strdup("");
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
			if (current->type == 7 && current->next->type == 21)
			{
				if (open(current->next->data, O_RDONLY) == -1)
				{
					perror(current->next->data);
					g.status = 1;
					exit(g.status);
				}
			}
			j++;
			if	(j == inp_redir)
			{
				//printf(" ---- current ->data %s \n", current->data);
				file = input_r(current);
				//printf("fileuuuh = %d \n", file);
				current->data = ft_strdup("");
				if(current->next && (current->next->type == 21 || current->next->type == 35 
					|| current->next->type == 36 || current->next->type == 37))
					current->next->data = ft_strdup("");
				if (current->type == 33 && (current->next->next->type == 39))
					current->next->next->data = ft_strdup("");
			}
			else
			{
				current->data = ft_strdup("");
				if (current->next)
				{
					current = current->next;
					current->data = ft_strdup("");
				}	
				else
					break ;
				if (current->next->type == 39)
				{
					current->next->data = ft_strdup("");
				}
			}
		}
		if (current->next)
		{
			current = current->next;
		}
		else
			break ;
	}
	delete_node(&list);
	//affiche(list->process);
	return (file);
}

void	child_process_simple(t_exec_s exec, t_flist *list, char **envp)
{
	manage_redirections(&list);
	exec.cmd_arg = list_to_tab(list->process);
	if (!exec.cmd_arg)
		exit(0);
	if (is_builtin(exec.cmd_arg[0]))
	{
		exec_builtin(exec.cmd_arg, envp);
	}
	else
	{
		exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
		if (!exec.cmd)
		{
			perror("minishell: cmd");
			g.status = 127;
			return ;
		}
		//printf("exec cmd = %s\n", exec.cmd);
		if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		{
			perror("minishell: cmd");
			g.status = 126;
			return ;
		}
	}
}

int	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;
	int		file;
	int		wstatus;

//	affiche(list->process);
	wstatus = 0;
	g.status = 0;
	shell_parameter_expansion(list->process, env);
	//file = manage_redirections(&list);
	//affiche(list->process);
	//printf("file == %d \n", file);
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	// arg = list_to_tab(list->process);
	exec.pid = fork();
	if (exec.pid == -1)
		exit(0);
	else if (!exec.pid)
		child_process_simple(exec, list, env);
	//close(file);
	//free(arg);
	waitpid(exec.pid, &wstatus, 0);
	printf("wstatus --> %d \n", wstatus);
	printf("G.STATUS dans exec_simple_cmd = %d\n", g.status);
	return (wstatus);
}