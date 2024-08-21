#include "builtins.h"

void do_exit(char **args)
{
    //TENGO QUE PRINTEAR PREV_EXIT_STATUS PARA VER CÓMO FUNCIONA Y VER SI LO MODIFICO AHORA O LUEGO
    int exit_status = prev_exit_status(0);  //coge el último estado sin modificarlo al principio

    if (args[1] != NULL)
    {
        int status;
        status = ft_atoi(args[1]);
        
        if (status >= 0 && status <= 255)
            exit_status = status;
        else
        {
            printf("errorcito\n");
            exit_status = 2;
        }
    }
    // prev_exit_status(exit_status);????? no lo sé
    printf("byebye<3\n");
    exit(exit_status);
    //intuyo que después de ejecutar el comando habrá que pasarle el status nuevo a prev_Exit_Status
}