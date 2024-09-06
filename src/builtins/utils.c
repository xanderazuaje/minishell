#include "builtins.h"

//aquí todo lo que necesito para ir modificando el env

//para saber longitud de env y poder alocar memoria suficiente
int envlen(char **env)
{
    int i;

    i = 0;
    while (env[i] != NULL)
        i++;
    return (i);
}

//para crear un nuevo env copia
void copy_env(char **env)
{
    int i;
    char **new_env;

    i = 0;
    new_env = malloc((envlen(env) + 2) * sizeof(char *));
    if (!new_env)
        return ;
        while (env[i] != NULL)
        {
            new_env[i] = env[i];
            i++;
        }
}
