/* hacer una función que recoja los comandos de la línea de comandos 
y en función de lo que se lea (strncmp) que le mande a una u otra función*/
#include "../minishell.h"

void exec_builtin(char **args, char **env)
{
    if (ft_strncmp(args[0], "cd", 3) == 0)
    {
        printf("FALLO AQUI 1\n");
        do_cd(args);
    }
    //if (ft_strcmp(args[0], "env") == 0)
      //  result = do_env(args);
    if (ft_strncmp(args[0], "pwd", 4) == 0)
    {
        printf("FALLO AQUI 2\n");
        do_pwd();
    }
    if (ft_strncmp(args[0], "exit", 5) == 0)
    {
        printf("hooola gente\n");
        do_exit(args);
    }
    printf("AQUI FUNCIONA\n");
}
