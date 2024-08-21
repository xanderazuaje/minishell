#include "builtins.h"

void do_exit(char **args)
{
    int exit_status = prev_exit_status(0);

    if (args[1] != NULL)
    {
        int status;
        status = ft_atoi(args[1]);
        
        if (status < 0)
			exit_status = 179;
        else if (status > 255)
            exit_status = 244;
        else
            exit_status = status;
    }
    prev_exit_status(exit_status);
    printf("byebye<3\n");
    exit(exit_status);
}