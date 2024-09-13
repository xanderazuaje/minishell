#include "builtins.h"


int check_var(char *name, char **new_env, char **env)
{
    int i;
    char *new_var;
    int namelen;
    (void) env;

    i = 0;
    namelen = ft_strlen(name) - 1;
    new_var = malloc((namelen + 1) * sizeof(char *)); //crear nueva variable name=value
    if (!new_var)
        return -1;
    while (name[i])
    {
        new_var[i] = name[i];
        i++;
    }
    new_var[i] = '\0';
    i = 0;
    printf("llego?\n");
    while (new_env[i] != NULL) //mirar si existe ya la variable
    {
        if (strncmp(new_env[i], name, namelen) == 0 && new_env[i][namelen + 1] == '=') //si existe? FUNCIONA COMPROBAO
        {
            free(new_env[i]); //libero la variable
            printf("borradooo jeje\n");
            break;
        }
        i++;
    }
    //FALTA SI NO EXISTE LA VARIABLE NAME
    //unset: `hola=1': not a valid identifier, cuando el name (sin el igual, solo el nombre de la variable) no corresponde.
    //es decir, si yo hago export hola=1, si hago unset hola=1 no funciona, solo funciona si hago unset hola.

    //CUIDADO, SE PUEDE HACER EXPORT HOLA=HOLA=1 Y SE QUEDA REGISTRADO TAL CUAL, PERO NO SE PUEDE HACER UNSET HOLA=HOLA
    printf("falloooo?\n");
    i = 0;
    //FALLA AQUÍ PORQUE NO SE PORQUE TIENE QUE COPIAR SOLO DONDE NO HAY NULOS Y CUANDO HE HECHO FREE SE HA DEBIDO BORRAR
    //Y CONVERTIR EN NULO Y AHORA DEJA EL HUECO Y POR ESO PETA.
    while (i < envlen(env))
    {
        if (new_env[i] != NULL)
            env[i] = new_env[i];
        i++;
    }
    env[i] = NULL;
    //COMPROBACIÓN
    // i = 0;
    // while (env[i] != NULL)
    // {
    //     printf("%s\n", env[i]);
    //     i++;
    // }
    return 0;
}

int do_unset(char **args, char **env)
{
    char *name; //unset NAME=VALUE
    char **new_env;
    int i;

    i = 0;
    name = malloc((ft_strlen(args[1]) + 1) * sizeof(char *)); //incluye la longitud de name + 1
    if (!name)
        return -1;
    while (args[1][i] != '\0')
    {
        name[i] = args[1][i];
        i++;
    }
    name[i] = '\0';
    new_env = malloc((envlen(env)) * sizeof(char *));
    if (!new_env)
         return -1;
    i = 0;
    while (i < envlen(env))
    {
        new_env[i] = ft_strdup(env[i]);
        printf("%s\n", new_env[i]);
        i++;
    }
    printf("hola aquí llego\n");
    if (check_var(name, new_env, env) != 0) 
    {
        perror("unset");
        return 1;
    }
    return 0;
}