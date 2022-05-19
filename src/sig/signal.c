#include "../../includes/minishell.h"

static void    handler(int sig)
{
    if (sig == SIGINT)
    {
        // affiche un nouveau prompt (SIGINT = ctrl -c)
        //ft_putchar_fd('\n', 0);
		rl_replace_line("", 0);
        write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
        //printf("la\n");
		//get_prompt();
    }
    else if (sig == SIGQUIT)
    {
        return ;
    }
}

int manage_signal(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	//signal()
    return (0);
}