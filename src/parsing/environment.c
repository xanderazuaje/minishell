/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 14:43:38 by xazuaje-         ###   ########.fr       */
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
