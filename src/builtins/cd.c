/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/02 12:04:48 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	go_there(char **args)
{
	char	*path;

	path = args[1];
	if (chdir(path) != 0)
		return (perror("chdir"), 1);
	return (0);
}

int	go_home(char **env)
{
	char	*home;

	home = get_var_val("$HOME", env, 0);
	if (!home)
		return (perror("HOME not set"), 1);
	if (chdir(home) != 0)
		return (perror("chdir to home"), 1);
	free(home);
	return (0);
}

int	do_cd(char **args, char **env)
{
	if (args[1] == NULL)
		return (go_home(env));
	return (go_there(args));
}
