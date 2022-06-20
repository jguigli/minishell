#include "../../includes/minishell.h"

// void	freeing(char *paths[])
// {
// 	int	i;

// 	i = 0;
// 	while (paths[i])
// 	{
// 		free(paths[i]);
// 		paths[i] = NULL;
// 		i++;
// 	}
// 	free(paths);
// 	paths = NULL;
// }

void	freeing_execution(t_exec_s	exec, int error)
{
	(void)exec;
	// freeing(cmd_opt);
	// free(cmd);
	// freeing(paths);
	error_msgs(error, "");
}

void	freeing_cmd(t_exec_s exec)
{
	(void)exec;
	// freeing(cmd_opt);
	// free(cmd);
	// freeing(paths);
	cmd_not_found(CMD, exec.cmd_arg[0]);
	//printf("looooool not FOUUUUND");
}

void	freeing_execution_c(t_exec_c exec, int error)
{
	(void)exec;
	// freeing(cmd_opt);
	// free(cmd);
	// freeing(paths);
	error_msgs(error, "");
}

void	freeing_cmd_c(t_exec_c exec)
{
	(void)exec;
	// freeing(cmd_opt);
	// free(cmd);
	// freeing(paths);
	cmd_not_found(CMD, exec.cmd_arg[0]);
}

void	free_datas(t_datas *data)
{
	if (data->data)
		free(data->data);
	if (data->t_token)
		free (data->t_token);
}

void	free_dblist(t_datas *first)
{
	t_datas	*current;
	t_datas	*to_free;

	current = first;
	while (current)
	{
		to_free = current;
		current = current->next; //rajouter condition de secu
		free_datas(to_free);
		free(to_free);
	}
}

void	free_flist(t_flist	*first)
{
	t_flist	*current;
	t_flist	*to_free;

	current = first;
	if (first)
	{
		while (current)
		{
			to_free = current;
			free_dblist(current->process->first);
			current = current->next;
			free(to_free);
		}
	}
}

void	free_exec_simple(t_exec_s *exec)
{
	int i;

	if (exec->path)
		free(exec->path);
	if (exec->cmd_path)
	{
		i = 0;
		while (exec->cmd_path[i])
			free(exec->cmd_path[i++]);
		free(exec->cmd_path);
	}
	if (exec->cmd_arg)
	{
		i = 0;
		while (exec->cmd_arg[i])
			free(exec->cmd_arg[i++]);
		free(exec->cmd_arg);
	}
	if (exec->cmd)
		free(exec->cmd);
}

void	free_exec_complex(t_exec_c *exec)
{
	int i;

	if (exec->pid)
		free(exec->pid);
	if (exec->pipe)
		free(exec->pipe);
	if (exec->path)
		free(exec->path);
	if (exec->cmd_path)
	{
		i = 0;
		while (exec->cmd_path[i])
			free(exec->cmd_path[i++]);
		free(exec->cmd_path);
	}
	if (exec->cmd_arg)
	{
		i = 0;
		while (exec->cmd_arg[i])
			free(exec->cmd_arg[i++]);
		free(exec->cmd_arg);
	}
	if (exec->cmd)
		free(exec->cmd);	
}

void	ft_free(t_main *main)
{
	int	i;

	i = 0;
	if (main->env)
	{
		while (main->env[i])
			free(main->env[i++]);
		free(main->env);
	}
	free_flist(main->start);
	free_exec_complex(main->exec_c);
	free_exec_simple(main->exec_s);
	free(main);
}
