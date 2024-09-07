#include "builtins.h"

int add_to_env(char *name, char *value, char **new_env)
{
    //int i;
    char *new_var;
    (void) new_env;
    int namelen;

    //i = 0;
    namelen = ft_strlen(name);
    printf("esto mide name: %d\n", namelen);
    printf("esto mide value: %zu\n", ft_strlen(value));
    new_var = malloc((namelen + ft_strlen(value)) * sizeof(char *)); //crear nueva variable name=value
    if (!new_var)
        return -1;
    printf("esto mide la nueva variable: %zu\n", namelen + ft_strlen(value));
    // while (new_env[i]) //mirar si existe ya la variable
    // {
    //     if (ft_strncmp(new_env[i], name, namelen) == 0 && new_env[i][namelen] == '=') //si existe?
    //     {
    //         free(new_env[i]); //reemplazo la existente
    //         new_env[i] = new_var;
    //         return 0;
    //     }
    //     i++;
    // }
    // //si no existe la agrego
    // new_env[i] = new_var;
    // new_env[i + 1] = NULL;
    return 0;
}

int do_export(char **args, char **env) 
{
    char *equal_sign;
    char *name; //export NAME=VALUE
    char **new_env;
    int i;

    //FALLA QUE LE ESTOY PASANDO NAME COMO TODO EL STR Y TENGO QUE PASARLE SOLO HASTA EL =
    i = 0;
    equal_sign = ft_strchr(args[1], '='); //busca a ver donde está el = (a partir de ahí, se coloca)
    if (!equal_sign) 
    {
        perror("export: not a valid identifier");
        return 1;
    }
    printf("equal sign: %s\n", equal_sign); //AQUI SACO =VALUE O LO QUE VA DETRÁS DEL NAME
    printf("esto ocupa name: %zu\n", len_to_char(args[1], '=') - 1);
    name = malloc(len_to_char(args[1], '=') * sizeof(char *)); //incluye la longitud de name + 1
    if (!name)
        return -1;
    while (args[1][i] != '=')
    {
        name[i] = args[1][i];
        i++;
    }
    name[i] = '\0';
    printf("esto vale name: %s\n", name);
    new_env = malloc((envlen(env) + 2) * sizeof(char *));
    if (!new_env)
         return -1;
    i = 0;
    while (i < envlen(env))
    {
        new_env[i] = ft_strdup(env[i]);
        i++;
    }
    if (add_to_env(name, equal_sign, new_env) != 0) 
    {
        perror("export");
        return 1;
    }
    return 0;
}