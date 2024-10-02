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
char **copy_env(char **env)
{
    int i;
    char **new_env;

    i = 0;
    new_env = malloc((envlen(env) + 2) * sizeof(char *));
    if (!new_env)
        return NULL;
    while (env[i] != NULL)
    {
        new_env[i] = strdup(env[i]);  // Duplica cada cadena
        if (!new_env[i])  // Verifica si hubo error en strdup
        {
            // Liberar las anteriores cadenas duplicadas en caso de error
            while (i-- > 0)
                free(new_env[i]);
            free(new_env);
            return NULL;
        }
        i++;
    }
    new_env[i] = NULL;  // Termina la lista de cadenas con NULL
    return new_env;
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void printenv(char **envcopy)
{
    int i;

    i = 0;
    while (envcopy[i])
    {
        printf("%s\n", envcopy[i]);
        i++;
    }
}