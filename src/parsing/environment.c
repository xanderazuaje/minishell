/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/01 11:23:37 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 10/31/24.
//
#include "parser.h"

char **envcopy(char **env)
{
	char **newenv;
	size_t len;

	len = 0;
	while (env[len++]){}
	newenv = malloc(sizeof(char *) * len);
	len = 0;
	while (env[len])
	{
		newenv[len] = ft_strdup(env[len]);
		len++;
	}
	newenv[len] = NULL;
	return newenv;
}

void freeenv(char ***env)
{
	size_t i;
	i = 0;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
}

void insert_variable(char *full_str, char ***env)
{
	char **new_env;
	int i;

	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], full_str, len_to_char((*env)[i], '=')) == 0)
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup(full_str);
			return;
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
    new_env[i] = ft_strdup(full_str);
    new_env[i + 1] = NULL;
    freeenv(env);
    *env = new_env;
}
