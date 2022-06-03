#include "../../includes/minishell.h"

void	child_process_simple(t_exec_s exec, char **arg, char **envp)
{
	exec.cmd_arg = arg;
	if (!exec.cmd_arg)
		exit(0);
	exec.cmd = get_command(exec.cmd_path, exec.cmd_arg[0]);
	if (!exec.cmd)
		exit(0);
	if (execve(exec.cmd, exec.cmd_arg, envp) == -1)
		exit(0);
}

int	output_r(t_datas *output_r)
{
	printf("OUT PUT R%s\n", output_r->next->data);
	int file;
	int	old_fd;

	file = open(output_r->next->data, O_TRUNC | O_CREAT | O_RDWR, 000644);
	if	(file < 0)
		error_msgs();
	old_fd = dup(1);
	dup2(file, STDOUT_FILENO);
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
	while(list)
	{
		current =  list->process->first;
		while(current)
		{
			printf("data %s\n", current->data);
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
				stock_next = current;
				stock_prev->next = stock_next;
				stock_next->previous = stock_prev;
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
}

int	manage_redirections(t_flist **li)
{
	t_flist	*list;
	int	inp_redir;
	int	outp_redir;
	int	i;
	int	j;
	t_datas	*current;

	i = 0;
	j = 0;
	list = *li;
	inp_redir = list->nb_heredoc + list->nb_lred;
	outp_redir = list->nb_rred_app + list->nb_rred;
	current = list->process->first;
	//affiche(list->process);
	while(current)
	{
		//printf("curent -> data ==> %s \n", current->data);
		if	(current->type == 6 || current->type == 38)
		{
			i++;
			//printf("i = %d \n", i);
			if	(i == outp_redir)
			{
				//printf("tesssst \n");
				output_r(current);
			}
			else
			{
	
				current->data = ft_strdup("");
				current->next->data = ft_strdup("");
				
			}
		}
		else if	(current->type == 7 || current->type == 33)
		{
			j++;
			//printf("j = %d \n", j);
			if	(j == inp_redir)
			{
				//printf("tesssst 2222222\n");
				input_r(current);
			}
			else
			{
				current->data = ft_strdup("");
				if (current->next)
				{
					current->next->data = ft_strdup("");
				}
				else
					break ;
				//printf("current->data ==> %d ---- next next data --> %s\n", current->next->next->type, current->next->next->data);
				if (current->type == 33 && (current->next->next->type == 39))
				{
					current->next->next->data = ft_strdup("");
				}
			}
		}
		if (current->next)
			current = current->next;
		else
			break ;
	}
	delete_node(&list);
	//affiche(list->process);
	return (0);
}

void	exec_simple_cmd(t_flist *list, char **env) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{
	t_exec_s	exec;
	char	**arg;

	shell_parameter_expansion(list->process, env);
	manage_redirections(&list);
	exec.path = search_in_env_var("PATH", env); // plantage
	exec.cmd_path = ft_split(exec.path, ':');
	arg = list_to_tab(list->process);
	if (is_builtin(arg[0]))
		exec_builtin(arg, env);
	else
	{
		exec.pid = fork();;
		if (exec.pid == -1)
			exit(0);
		else if (!exec.pid)
			child_process_simple(exec, arg, env);
	}
	free(arg);
	waitpid(exec.pid, NULL, 0);
}