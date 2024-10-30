/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/30 21:00:08 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//  RUTA ABSOLUTAAAA?
//FALLA GETENV PORQUE TENGO QUE MANDARLE EL ENV MIOOOOOO PUTAAAAAAAAA

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

int go_there(char **args)
{
    char *path = args[1];

    if (chdir(path) != 0) //cambia a la ruta especificada
        return (perror("chdir"), 1);

    return 0;
}

int go_home(char **env)
{
    char *home;

    home = get_var_val("$HOME", env, 0);
    if (!home)
        return (perror("HOME not set"), 1);
    if (chdir(home) != 0)
        return (perror("chdir to home"), 1);
    free(home);
    return 0;
}


int do_cd(char **args, char **env)
{
    if (args[1] == NULL)
        return (go_home(env));
    return (go_there(args));
}