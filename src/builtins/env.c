#include "builtins.h"

void do_env(char **envp)
{
    int i;

    i = 0;
    printf("ESTOY EN ENV\n");
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}