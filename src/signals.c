#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void sigint_handler(int sig)
{
    printf("Eres gay por pulsar CtrlC\n");
    //aqui falla porque no coge bien la libreria readline creo
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    (void) sig;
}

void	init_signals(void)
{
	signal(SIGINT, sigint_handler); //este tiene que interrumpir el proceso el ctrol c
	signal(SIGQUIT, SIG_IGN); //este tiene que ignorar el ctrol y barrita
}