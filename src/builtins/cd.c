/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:25:43 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/16 19:47:52 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 09:32:28 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	go_there(char **args)
{
	char	*path;

	path = args[1];
	if (access(path, F_OK) != 0)
	{
		perror("cd");
		return (2);
	}
	if (chdir(path) != 0)
		return (perror("cd"), 1);
	return (0);
}

int	go_home(char **env)
{
	char	*home;

	home = get_var_val("$HOME", env);
	if (!home)
		return (perror("cd"), 1);
	if (chdir(home) != 0)
		return (perror("cd"), 1);
	free(home);
	return (0);
}

int	do_cd(char **args, char **env)
{
	if (args[1] == NULL)
		return (go_home(env));
	if (args[2] != NULL)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	return (go_there(args));
}
