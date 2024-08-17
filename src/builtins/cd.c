#include "minishell.h"

//char *remove_quotes()

void update_old_pwd(char **args)
{
    //aquí un while que vaya leyendo el env y busque si la variable OLDPWD ya existe
        //si existe que reemplace su valor
    //si no existe, ampliamos el array y añadimos la nueva variable OLDPWD al final
    
}

int path(char *cd, char *command, char **args)
{
    char *temp;

    //temp = remove_quotes(command);
    //Si retrocedo, que me lleve a la ruta guardada en OLDPWD (que es la anterior en la que estuve)
    if (!strncmp(temp, "-", 2))
    {
        chdir(getenv("OLDPWD"));
        return 0;
    }
    if (!chdir(temp))
        perror("No such file or directory!"); //falta imprimir por error
    else
    {
        free(temp);
        update_old_pwd(args);
        //cambiar oldpwd a pwd actual
        return 0;
    }
    free(temp);
    return 1;
}

void do_cd(char *args)
{
    // Si el usuario no pasa ningún argumento después de cd
    if (!args[1])
    {
        char *home = getenv("HOME");

        if (home == NULL)
            perror("cd: HOME environment variable is not set\n");
        else
        {
            // Manda al usuario al home
            if (!chdir(home))
                perror("Couldn't change directory");
        }
    }
    // Si el usuario pasa argumentos después de cd
    {
        if (!chdir(args)) //con esto se comprueba que no le pasan más de un comando???
            perror("Couldn't change directory");
    }
}