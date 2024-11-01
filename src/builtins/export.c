/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:48:27 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 17:21:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int builtin_export(char *str, char ***env)
{
    char	*equal_sign;
    char	**new_env;
    int	    i;

    i = 0;
    equal_sign = ft_strchr(str, '=');
    if (equal_sign == NULL)
        return 0;
    while (str[i] && str[i] != '=')
    {
        if (!ft_isalnum(str[i]) || !ft_isalpha(str[0]))
        {
            write(2, "export: not a valid identifier\n", 32);
            return 1;
        }
        i++;
    }
    new_env = malloc((envlen(*env) + 2) * sizeof(char *));
    i = 0;
    while (i < envlen(*env))
    {
        new_env[i] = ft_strdup((*env)[i]);
        i++;
    }
    new_env[i] = ft_strdup(str);
    new_env[i + 1] = NULL;
    freeenv(env);
    *env = new_env;
    return 0;
}

int do_export(char **args, char ***env)
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