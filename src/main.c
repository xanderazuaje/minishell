/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/09 15:15:22 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	int exit_status;
	t_cmdlist *cmds;

	(void) env;
	exit_status = 0;
	(void ) argc;
	(void ) argv;
	while (1)
	{
		line = readline("\033[0;33mbASSh> \033[0;0m");
		if (line && *line)
			add_history(line);
		if (!line)
		{
			free(line);
			exit(exit_status);
		}
		cmds = parse_str(line, env);
		if (!cmds)
			continue ;
		executor(cmds, env);
		free_cmd(cmds);
	}
}
