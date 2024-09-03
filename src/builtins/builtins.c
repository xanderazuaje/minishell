/* hacer una función que recoja los comandos de la línea de comandos 
y en función de lo que se lea (strncmp) que le mande a una u otra función*/
#include "../minishell.h"

void exec_builtin(char **args, char **env)
{
    if (ft_strncmp(args[0], "env", 4) == 0)
        do_env(env);
    if (ft_strncmp(args[0], "pwd", 4) == 0)
        do_pwd();
    if (ft_strncmp(args[0], "exit", 5) == 0)
        do_exit(args);
    if (ft_strncmp(args[0], "cd", 3) == 0)
        do_cd(args, env);
}
