#include "minishell.h"

void do_pwd(void)
{
    char *path;

    path = getcwd(NULL, 0);
    printf("%s\n", path);
    free(path);
}