#include "builtins.h"

int go_there(char **args, char **env)
{

}

int go_back(char **env)
{
    
}

int go_home(char **env)
{
    char *path;
    char *home;

    path = getcwd(NULL, 0);
    home = getenv("HOME");
    if (!home)
        return (perror("HOME not set"), 1);
    if (!chdir(home))
        return (perror("home"), 1);
    if (!update_old_pwd(env)) //aquí actualizo el OLDPWD
        return (perror("update_old_pwd() error"), 1);
    printf("esto es el path guardao\n", path);
    path = getcwd(NULL, 0);
    if (!path)
        return (perror("getcwd() error"), 1);
    //aquí hay que cambiar PWD igual que update_old_pwd
    free(home);
    return 0;
}

int update_old_pwd(char **env)
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
    return 0;
}

void do_cd(char **args, char **env)
{
    if (args[1] == NULL)
        return (go_home(env));
    else if (strncmp(args[1], "-", 2) == 0)
        return (go_back(env));
    else
        return (go_there(args, env));
}