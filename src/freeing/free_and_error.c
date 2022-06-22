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