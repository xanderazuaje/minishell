#include "builtins.h"

// //char *remove_quotes()

int envlen(char **env)
{
    int i;

    i = 0;
    while (env[i] != NULL)
        i++;
    return (i);
}

int update_old_pwd(char **args, char **env)
{
    int i;
    char *actualpath;
    int len;
    char **new_env;

    i = 0;
    len = envlen(env);
    actualpath = getcwd(NULL, 0);
    new_env = malloc((len + 2) * sizeof(char *));
    while (env[i] != NULL)
    {
        new_env[i] = env[i];
        if (ft_strncmp(env[i], "OLDPWD=", 7) == 0) //existe
        {
            //si existe no tengo que crear la variable, simplemente cambiar donde toca
            new_env[i] = ft_strjoin("OLDPWD=", actualpath);
        }
        i++;
    }
    new_env[i - 1] = ft_strjoin("OLDPWD=", actualpath);
    new_env[i] = NULL;
    (void) args;
    return 0;
}

int path(char **args, char **env)
{
    char *temp = NULL;

    //Si retrocedo, que me lleve a la ruta guardada en OLDPWD (que es la anterior en la que estuve)
    if (!strncmp(temp, "-", 2))
    {
        chdir(getenv("OLDPWD"));
        return 0;
    }
    if (!chdir(temp))
        perror("No such file or directory!");
    else
    {
        free(temp);
        update_old_pwd(args, env);
        return 0;
    }
    free(temp);
    (void) args;
    return 1;
}

void do_cd(char **args, char **env)
{
    (void) args;
    (void) env;
    //si no hay argumentos entonces (go home)
    //si hay 1 argumento entonces (go there)
}