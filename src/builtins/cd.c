#include "builtins.h"

//  RUTA ABSOLUTAAAA?

int update_old_pwd(char **env)
{
    int i;
    char *actualpath;
    int len;
    char **new_env;
    int exists;

    i = 0;
    exists = 0;
    len = envlen(env);
    actualpath = getcwd(NULL, 0);
    if (!actualpath)
        return (perror("getcwd() error"), 1);
    new_env = malloc((len + 2) * sizeof(char *));
    while (env[i] != NULL)
    {
        new_env[i] = env[i];
        if (ft_strncmp(env[i], "OLDPWD=", 7) == 0) //existe
        {
            //si existe no tengo que crear la variable, simplemente cambiar donde toca
            new_env[i] = ft_strjoin("OLDPWD=", actualpath);
            exists = 1; //si existe
        }
        i++;
    }
    //si no existe la creas
    if (!exists)
    {
        new_env[i] = ft_strjoin("OLDPWD=", actualpath);
        new_env[i + 1] = NULL;
    }
    else
        new_env[i] = NULL;
    free(actualpath);
    //actualizar env
    i = 0;
    //******* SOLUCIONADO -> FALTA METERLO EN EL ENV ORIGINAL PARA QUE AL HACER ENV SIGA APARECIENDO LA VARIABLE */
    while (new_env[i] != NULL)
    {
        env[i] = new_env[i];
        i++;
    }
    env[i] = NULL;
    return 0; //si todova bien
}

int update_pwd(char **env)
{
    int i;
    char *actualpath;
    int len;
    char **new_env;
    int exists;

    i = 0;
    exists = 0;
    len = envlen(env);
    actualpath = getcwd(NULL, 0);
    if (!actualpath)
        return (perror("getcwd() error"), 1);
    new_env = malloc((len + 2) * sizeof(char *));
    while (env[i] != NULL)
    {
        new_env[i] = env[i];
        if (ft_strncmp(env[i], "PWD=", 4) == 0) //existe
        {
            //si existe no tengo que crear la variable, simplemente cambiar donde toca
            new_env[i] = ft_strjoin("PWD=", actualpath);
            exists = 1; //si existe
        }
        i++;
    }
    //si no existe la creas
    if (!exists)
    {
        new_env[i] = ft_strjoin("PWD=", actualpath);
        new_env[i + 1] = NULL;
    }
    else
        new_env[i] = NULL;
    free(actualpath);
    //actualizar env
    i = 0;
    //******* SOLUCIONADO -> FALTA METERLO EN EL ENV ORIGINAL PARA QUE AL HACER ENV SIGA APARECIENDO LA VARIABLE */
    while (new_env[i] != NULL)
    {
        env[i] = new_env[i];
        i++;
    }
    env[i] = NULL;
    return 0; //si todova bien
}

int go_there(char **args, char **env)
{
    char *path = args[1];

    if (chdir(path) != 0) //cambia a la ruta especificada
        return (perror("chdir"), 1);

    if (update_old_pwd(env) != 0) //actualiza OLDPWD
        return (perror("update_old_pwd() error"), 1);

    if (update_pwd(env) != 0) //actualiza PWD
        return (perror("update_pwd() error"), 1);

    return 0;
}

int go_back(char **env)
{
    char *oldpwd = getenv("OLDPWD");

    if (!oldpwd)
        return (perror("OLDPWD not set"), 1);

    if (chdir(oldpwd) != 0) //cambia al directorio anterior
        return (perror("chdir to OLDPWD"), 1);

    if (update_old_pwd(env) != 0) //actualiza OLDPWD
        return (perror("update_old_pwd() error"), 1);

    if (update_pwd(env) != 0) //actualiza PWD
        return (perror("update_pwd() error"), 1);

    printf("%s\n", oldpwd); //imprime OLDPWD como en bash
    return 0;
}

int go_home(char **env)
{
    char *home;

    home = getenv("HOME");
    if (!home)
        return (perror("HOME not set"), 1);

    if (chdir(home) != 0)
        return (perror("chdir to home"), 1);

    if (update_old_pwd(env) != 0)
        return (perror("update_old_pwd() error"), 1);
    
    if (update_pwd(env) != 0)
        return (perror("update_pwd() error"), 1);

    return 0;
}


int do_cd(char **args, char **env)
{
    if (args[1] == NULL)
        return (go_home(env));
    else if (strncmp(args[1], "-", 2) == 0)
        return (go_back(env));
    else
        return (go_there(args, env));
}