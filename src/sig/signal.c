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
    else if (sig == SIGQUIT)
    {
        return ;
    }
}

int manage_signal(void)
{
	//signal(SIGINT, handler);
	signal(SIGQUIT, handler);
    return (0);
}