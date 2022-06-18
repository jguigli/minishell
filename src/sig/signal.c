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
	(void)sig;
	ft_putstr_fd("\b \b\b \b \b", 2);
	return ;
}

void	ft_sig_child(int sig)
{
	(void)sig;
	// close(0);
	// close(1);
	//printf("loull\n");
	kill(getppid(), SIGINT);
	//g.sigintos = 2;
	status = 1;
	exit(status);
	return ;
}

int	manage_signal(void)
{
	signal(SIGINT, &ft_sigint);
	signal(SIGQUIT, &ft_sigquit);
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
		signal(SIGINT, &ft_sig_child);
		//printf("retour signal --> %d\n", signal(SIGINT, &ft_sig_child));
		// printf("hello\n");
		signal(SIGQUIT, SIG_IGN);
	}
	else if (pid > 0)
	{
		//printf("wesho\n");
		signal(SIGINT, &ft_sig_fork_par);
		signal(SIGQUIT, &ft_sig_fork_par);
	}
	else 
		return ;
}