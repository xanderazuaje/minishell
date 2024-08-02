/* hacer una función que recoja los comandos de la línea de comandos 
y en función de lo que se lea (strncmp) que le mande a una u otra función*/
#include "minishell.h"

int exec_builtin(char **args, char **env)
{
    int result;
    
    result = 0;
    if (ft_strcmp(args[0], "cd") == 0)
        result = do_cd(args);
    if (ft_strcmp(args[0], "env") == 0)
        result = do_env(args);
    if (ft_strcmp(args[0], "pwd") == 0)
        result = do_pwd();
    if (ft_strcmp(args[0], "exit") == 0)
        result = do_env(args);
    return (result);
}
