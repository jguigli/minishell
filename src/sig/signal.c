#include "../../includes/minishell.h"


// ************* MANAGE SIGNALS FROM THE PARENT
void	ft_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_sigquit(int sig)
{
	(void)sig;
	ft_putstr_fd("\b \b\b \b \b", 2);
	return ;
}

int	manage_signal()
{
	signal(SIGINT, &ft_sigint);
	signal(SIGQUIT, &ft_sigquit);
	return (0);
}
// ***************************************************

void	ft_sig_child(int sig)
{
	(void)sig;
	write(1, "Here the child\n", 16);
	status = 1;
	exit(1);
	return ;
}

void	ft_test(int sig)
{
	write(1, "loliloooool\n", 13);
	
}

void	ft_cancel_sigint(int sig)
{
	(void)sig;
	// write(1, "\n", 1);
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
	signal(SIGINT, SIG_IGN);
	//write(1, "SIGINT\n",7);
	//status = 130;
}

void	ft_cancel_sigquit(int sig)
{
	(void)sig;
	signal(SIGQUIT, SIG_IGN);
	//write(1, "SIQUIT\n", 7);
	return ;
}


int	cancel_parent_signal(void)
{
	signal(SIGINT, &ft_cancel_sigint);
	signal(SIGQUIT, &ft_cancel_sigquit);
	return (0);
}

void	ft_sig_fork_par(int sig)
{
	(void)sig;
	if (sig == SIGINT)
	{
		//write(1, "\n", 1);
		//close(0);
		//close(1);
		//ft_putstr_fd("\b \b\b \b \b \b", 2);
		//close(0);
		//close(1);
		//printf("wesssssssssssssh\n");
		status = 130;
		return ;
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		status = 131;
	}
	return ;
}

void	ft_sig_fork(pid_t pid)
{
	//printf("pid t %d\n", pid);
	if (pid == 0)
	{
		signal(SIGINT, &ft_sigint);
	//printf("retour signal --> %zu\n", signal(SIGINT, &ft_sig_child));
		// printf("hello\n");
		signal(SIGQUIT, SIG_IGN);
	}
}