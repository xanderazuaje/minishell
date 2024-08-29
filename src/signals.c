#include "minishell.h"

void sig_handler(int sig)
{
    printf("Hola esto es pa saber si me hace\n");
    (void) sig;
}

void	init_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}