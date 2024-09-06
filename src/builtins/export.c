#include "builtins.h"

int add_to_env(char *name, char *value, char **new_env)
{
    int i;
    char *new_var;
    int namelen;

    i = 0;
    namelen = ft_strlen(name);
    new_var = malloc(namelen + ft_strlen(value) + 2); //crear nueva variable name=value
    if (!new_var)
        return -1;

    while (new_env[i]) //mirar si existe ya la variable
    {
        if (ft_strncmp(new_env[i], name, namelen) == 0 && new_env[i][namelen] == '=') //si existe?
        {
            free(new_env[i]); //reemplazo la existente
            new_env[i] = new_var;
            return 0;
        }
        i++;
    }
    //si no existe la agrego
    new_env[i] = new_var;
    new_env[i + 1] = NULL;
    return 0;
}

int do_export(char **args, char **env) 
{
    char *equal_sign;
    char *name; //export NAME=VALUE
    char *value;
    char **new_env;
    int i;

    name = (args[1]); //todo el primer argumento, ya luego veo cómo añado más variables jeje***
    equal_sign = ft_strchr(args[1], '='); //busca a ver donde está el = (a partir de ahí, se coloca)
    if (!equal_sign) 
    {
        perror("export: not a valid identifier");
        return 1;
    }
    *equal_sign = '\0';
    value = equal_sign + 1;
    new_env = malloc((envlen(env) + 2) * sizeof(char *));
    if (!new_env)
        return -1;
    i = 0;
    while (i < envlen(env))
    {
        new_env[i] = ft_strdup(env[i]);
        i++;
    }
    if (add_to_env(name, value, new_env) != 0) 
    {
        perror("export");
        return 1;
    }
    return 0;
}