#include "builtins.h"

//FALTA QUE SE PUEDA HACER CON VARIOS COMANDOS A LA VEZ (UNSET HOLA ADIOS BORRA HOLA Y ADIOS)
int check_var(char *name, char **new_env, char **env)
{
    int i;
    int namelen;

    i = 0;
    namelen = ft_strlen(name) - 1;
    printf("name: %s\n", name);
    while (new_env[i] != NULL) //mirar si existe ya la variable
    {
        if (strncmp(new_env[i], name, namelen) == 0 && new_env[i][namelen + 1] == '=') //si existe? FUNCIONA COMPROBAO
        {
            while ((new_env)[i] != NULL)
			{
				(new_env)[i] = (new_env)[i + 1];
				i++;
			}
			break ;
        }
        i++;
    }
    //FALTA SI NO EXISTE LA VARIABLE NAME
    //unset: `hola=1': not a valid identifier, cuando el name (sin el igual, solo el nombre de la variable) no corresponde.
    //es decir, si yo hago export hola=1, si hago unset hola=1 no funciona, solo funciona si hago unset hola.

    //CUIDADO, SE PUEDE HACER EXPORT HOLA=HOLA=1 Y SE QUEDA REGISTRADO TAL CUAL, PERO NO SE PUEDE HACER UNSET HOLA=HOLA
    i = 0;
    while (new_env[i] != NULL)
    {
        env[i] = new_env[i];
        i++;
    }
    env[i] = NULL;
    return 0;
}

int builtin_unset(char *str, char **env)
{
    char *name; //unset NAME=VALUE
    char **new_env;
    int i;

    i = 0;
    name = malloc((ft_strlen(str) + 1) * sizeof(char *)); //incluye la longitud de name + 1
    if (!name)
        return -1;
    while (str[i] != '\0')
    {
        name[i] = str[i];
        i++;
    }
    name[i] = '\0';
    new_env = malloc((envlen(env) + 1) * sizeof(char *));
    if (!new_env)
         return -1;
    i = 0;
    while (i < envlen(env))
    {
        new_env[i] = ft_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    printf("hola aquí llego\n");
    if (check_var(name, new_env, env) != 0) 
    {
        perror("unset");
        return 1;
    }
    return 0;
}

int do_unset(char **args, char **env)
{
    int num;

    num = 1;
    while (args[num] != NULL && num > 0)
    {
        builtin_unset(args[num], env);
        num++;
    }
    return 0;
}