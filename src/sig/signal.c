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

// Cancelling parent signal in forks and defining child behaviour *********************

void	sig_quit_child(int sig)
{
	ft_putstr_fd("Quit (core dumped)\n", 2);
	status = 131;
}

int	manage_sig_in_forks(pid_t pid, t_main *main)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, &sig_quit_child);
	}
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}	
}
//****************************************************************