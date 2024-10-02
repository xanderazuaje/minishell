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
    {
        char **envcopy;
        int i;
        
        i = 0;
        envcopy = copy_env(env);
        if (!envcopy)
        {
            perror("Failed to copy environment");
            return;
        }
        do_cd(args, envcopy);
        while (env[i])
        {
            env[i] = envcopy[i];  //asigna valor
            i++;
        }
        env[i] = NULL;
        free(envcopy); //libera envcopy, ya que hemos copiado las cadenas en env
    }
    if (ft_strncmp(args[0], "echo", 5) == 0)
        do_echo(args);
    if (ft_strncmp(args[0], "export", 7) == 0)
        do_export(args, env);
    if (ft_strncmp(args[0], "unset", 6) == 0)
        do_unset(args, env);
}
