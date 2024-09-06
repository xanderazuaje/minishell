#include "builtins.h"

int has_flag(char *str)
{
    int i;

    i = 0;
    if (str[0] != '-' || str[1] != 'n')
        return 1;
    i++;
    while (str[i])
    {
        if (str[i] != 'n')
            return 1;
        i++;
    }
    return 0; //si si tiene la n flag
}

//POSIBLE INCONVENIENTE: SI PONGO ECHO -N -N -N HOLA, SOLO TIENE QUE IMPRIMIR HOLA, PERO SI PONGO
// ECHO -N HOLA -N TIENE QUE IMPRIMIR HOLA -N SOLUCIONADOOOO**

//ERROR CUANDO SOLO PONGO ECHO, POR QUÉ NO ME HACE CASO?

int do_echo(char **args)
{
    int linebr;
    int i;
    
    if (!args || !args[1])
        return (printf("\n"), 0);
    linebr = has_flag(args[1]); // 0 tiene, 1 no tiene
    i = 1;
    while (args[i] != NULL)
    {
        if (args[i][0] == '-' && args[i][1] == 'n') //si pones varias -n que las ignore
            i++;
        else
            break;
    }
    while (args[i] != NULL)
    {
        printf("%s", args[i]);
        if (args[i + 1] && args[i + 1][0] != '\0') // si hay varias palabras pues las tendrá que separar con espacios
			printf(" ");
        i++;
    }
    if (linebr == 1) // no tiene la flag
        printf("\n");
    return 0;
}