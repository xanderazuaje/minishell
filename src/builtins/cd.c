#include "builtins.h"

//  RUTA ABSOLUTAAAA?
//FALLA GETENV PORQUE TENGO QUE MANDARLE EL ENV MIOOOOOO PUTAAAAAAAAA

int update_old_pwd(char **envcopy)
{
    int i;
    char *actualpath;
    int len;
    char **new_env;
    int exists;

    i = 0;
    exists = 0;
    len = envlen(envcopy);
    actualpath = getcwd(NULL, 0);
    if (!actualpath)
        return (perror("getcwd() error"), 1);
    new_env = malloc((len + 2) * sizeof(char *));
    while (envcopy[i] != NULL)
    {
        new_env[i] = envcopy[i];
        if (ft_strncmp(envcopy[i], "OLDPWD=", 7) == 0) //existe
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
        envcopy[i] = new_env[i];
        i++;
    }
    envcopy[i] = NULL;
    return 0; //si todova bien
}

int update_pwd(char **envcopy)
{
    int i;
    char *actualpath;
    int len;
    char **new_env;
    int exists;

    i = 0;
    exists = 0;
    len = envlen(envcopy);
    actualpath = getcwd(NULL, 0);
    if (!actualpath)
        return (perror("getcwd() error"), 1);
    new_env = malloc((len + 2) * sizeof(char *));
    while (envcopy[i] != NULL)
    {
        new_env[i] = envcopy[i];
        if (ft_strncmp(envcopy[i], "PWD=", 4) == 0) //existe
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
        envcopy[i] = new_env[i];
        i++;
    }
    envcopy[i] = NULL;
    return 0; //si todova bien
}

int go_there(char **args, char **envcopy)
{
    char *path = args[1];

    printf("ESTO ES UNA PRUEBita\n");
    if (update_old_pwd(envcopy) != 0) //actualiza OLDPWD
        return (perror("update_old_pwd() error"), 1);

    if (chdir(path) != 0) //cambia a la ruta especificada
        return (perror("chdir"), 1);

    if (update_pwd(envcopy) != 0) //actualiza PWD
        return (perror("update_pwd() error"), 1);

    return 0;
}

int go_back(char **envcopy)
{
    char *oldpwd = getenv("OLDPWD"); //CAMBIAR ESSTOOO

    if (!oldpwd)
        return (perror("OLDPWD not set"), 1);

    if (update_old_pwd(envcopy) != 0) //actualiza OLDPWD
        return (perror("update_old_pwd() error"), 1);
    
    if (chdir(oldpwd) != 0) //cambia al directorio anterior
        return (perror("chdir to OLDPWD"), 1);
    
    if (update_pwd(envcopy) != 0) //actualiza PWD
        return (perror("update_pwd() error"), 1);

    do_pwd();

    return 0;
}

int go_home(char **envcopy)
{
    char *home;

    home = get_var_val("$HOME", envcopy, 0);
    printf("homecito: %s\n", home);
    if (!home)
        return (perror("HOME not set"), 1);
    if (update_old_pwd(envcopy) != 0)
        return (perror("update_old_pwd() error"), 1);
    if (chdir(home) != 0)
        return (perror("chdir to home"), 1);
    if (update_pwd(envcopy) != 0)
        return (perror("update_pwd() error"), 1);
    return 0;
}


int do_cd(char **args, char **envcopy)
{
    //printenv(envcopy);
    if (args[1] == NULL)
        return (go_home(envcopy));
    else if (strncmp(args[1], "-", 1) == 0)
        return (go_back(envcopy));
    else
        return (go_there(args, envcopy));
}