/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/02 12:11:18 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_unset(char *name, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < envlen(env) + 1 && env[j])
	{
		if (start_with(env[j], name))
		{
			free(env[j]);
			j++;
			continue ;
		}
		env[i] = env[j];
		i++;
		j++;
	}
	env[i] = NULL;
}

int	do_unset(char **args, char **env)
{
	int	num;

	num = 1;
	while (args[num] != NULL && num > 0)
	{
		builtin_unset(args[num], env);
		num++;
	}
	return (0);
}
