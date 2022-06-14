#include "../../includes/minishell.h"

static void    handler(int sig)
{
    if (sig == SIGINT)
    {
		rl_replace_line("", 0);
        write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
    }
    else if (sig == SIGQUIT) // en mode prompt quitter core dumped
    {
        return ;
    }
}

int manage_signal()
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);

    return (0);
}

// int	manage_signal_hd()
// {
// 	//free(buf);
// 	// close(fd);
// 	// fd = open(".hd1", O_TRUNC);
// 	// write(fd, "", 1);
// 	signal(SIGINT, handler);
// 	signal(SIGQUIT, handler);

//     return (0);
// 	// return (0);
// 	// signal(SIGINT, SIG_IGN);
// 	// signal(SIGQUIT, SIG_IGN);
// }

// void	ft_sig_fork_par(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		write(1, "\n", 1);
// 		g.status = 130;
// 	}
// 	else if (sig == SIGQUIT)
// 	{
// 		ft_putstr("Quit (core dumped)\n");
// 		g.status = 131;
// 	}
// }

// void	ft_sig_fork(int pid)
// {
// 	if (pid == 0)
// 	{
// 		signal(SIGINT, SIG_DFL);
// 		signal(SIGQUIT, SIG_DFL);
// 	}
// 	else
// 	{
// 		signal(SIGINT, ft_sig_fork_par);
// 		signal(SIGQUIT, ft_sig_fork_par);
// 	}	
// }