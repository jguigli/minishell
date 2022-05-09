#include "../../includes/minishell.h"

static void    handler(int sig)
{
    if (sig == SIGINT)
    {
        // affiche un nouveau prompt (SIGINT = ctrl -c)
        ft_putchar_fd('\n', 1);
        //printf("la\n");
    }
    else if (sig == SIGQUIT)
    {
        // ne rien faire (SIGABRT = ctrl -\)
    }
}

int manage_signal(void)
{
    struct sigaction act;
    struct sigaction oact;

    act.sa_handler = handler;
    sigaction(SIGINT, &act, &oact);
    sigaction(SIGABRT, &act, &oact);
    return (0);
}