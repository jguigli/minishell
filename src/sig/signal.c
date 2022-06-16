#include "../../includes/minishell.h"

// static void    handler(int sig)
// {
//     if (sig == SIGINT)
//     {
// 		rl_replace_line("", 0);
//         write(1, "\n", 1);
// 		rl_on_new_line();
// 		rl_redisplay();
//     }
//     else if (sig == SIGQUIT) // en mode prompt quitter core dumped
//     {
//         return ;
//     }
// }

// int manage_signal()
// {
// 	signal(SIGINT, handler);
// 	signal(SIGQUIT, handler);

//     return (0);
// }


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
	ft_putstr_fd("\b \b\b \b \b", 2);
	return ;
}

void	ft_sig_child(int sig)
{
	close(0);
	g.status = 1;
	return ;
}

int	manage_signal(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_sigquit);
	return (0);
}


void	ft_sig_fork_par(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g.status = 130;
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g.status = 131;
	}
}

void	ft_sig_fork(int pid)
{
	if (pid == 0)
	{
		signal(SIGINT, ft_sig_child);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (pid > 0)
	{
		signal(SIGINT, ft_sig_fork_par);
		signal(SIGQUIT, ft_sig_fork_par);
	}
	else 
		return ;
}