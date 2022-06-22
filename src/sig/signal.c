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

// Cancelling a signal in forks
int	manage_sig_in_forks(pid_t pid, t_main *main)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		//write(1, "\n", 2);
	}
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
	}
	
}