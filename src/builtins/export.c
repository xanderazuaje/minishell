#include "builtins.h"

int add_to_env(char *new_var, char **env, int len)
{
	int		i;
    char **copy_env;

    i = 0;
    copy_env = malloc((len + 2) * sizeof(char *));
    if (!copy_env)
		return -1;
    while (i < len)
	{
		copy_env[i] = ft_strdup(env[i]);
		i++;
	}
	copy_env[i] = ft_strdup(new_var);
	copy_env[i + 1] = NULL;
    i = 0;
    //******* SOLUCIONADO -> FALTA METERLO EN EL ENV ORIGINAL PARA QUE AL HACER ENV SIGA APARECIENDO LA VARIABLE */
    while (copy_env[i] != NULL)
    {
        env[i] = copy_env[i];
        i++;
    }
    env[i] = NULL;
    //COMPROBACIÓN FUNCIONA
    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return 0;
}

//************************CUIDADO, SE PUEDE HACER EXPORT HOLA=HOLA=1 Y SE QUEDA REGISTRADO TAL CUAL */

int check_env(char *name, char *value, char **new_env, char **env)
{
    int i;
    int j;
    char *new_var;
    int namelen;

    i = 0;
    namelen = ft_strlen(name);
    printf("esto mide name: %d\n", namelen);
    printf("esto mide value: %zu\n", ft_strlen(value));
    new_var = malloc((namelen + ft_strlen(value)) * sizeof(char *)); //crear nueva variable name=value
    if (!new_var)
        return -1;
    while (name[i])
    {
        new_var[i] = name[i];
        i++;
    }
    j = 0;
    while (value[j])
    {
        new_var[i] = value[j];
        i++;
        j++;
    }
    new_var[i] = '\0';
    printf("esto mide la nueva variable: %zu\n", namelen + ft_strlen(value));
    printf("esto es new_var: %s\n", new_var);
    i = 0;
    while (new_env[i] != NULL) //mirar si existe ya la variable
    {
        if (strncmp(new_env[i], name, namelen) == 0 && new_env[i][namelen] == '=') //si existe? FUNCIONA COMPROBAO
        {
            free(new_env[i]); //reemplazo la existente
            new_env[i] = new_var;
            return 0;
        }
        i++;
    }
    printf("aquí falla?¿?¿?¿?¿\n");
    //si no existe la agrego
    if (add_to_env(new_var, env, i) == -1)
        return (perror("export"), 1);
    return 0;
}

int builtin_export(char *str, char **env) 
{
    char *equal_sign;
    char *name; //export NAME=VALUE
    char **new_env;
    int i;

    i = 0;
    equal_sign = ft_strchr(str, '='); //busca a ver donde está el = (a partir de ahí, se coloca)
    if (!equal_sign) 
    {
        perror("export: not a valid identifier");
        return 1;
    }
    printf("equal sign: %s\n", equal_sign); //AQUI SACO =VALUE O LO QUE VA DETRÁS DEL NAME
    printf("esto ocupa name: %zu\n", len_to_char(str, '=') - 1);
    name = malloc(len_to_char(str, '=') * sizeof(char *)); //incluye la longitud de name + 1
    if (!name)
        return -1;
    while (str[i] != '=')
    {
        name[i] = str[i];
        i++;
    }
    name[i] = '\0';
    printf("esto mide env: %d\n", envlen(env));
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
    if (check_env(name, equal_sign, new_env, env) != 0) 
        return (perror("export2"), 1);
    return 0;
}

int do_export(char **args, char **env)
{
    int num;

    num = 1;
    while (args[num] != NULL && num > 0)
    {
        builtin_export(args[num], env);
        num++;
    }
    return 0;
}