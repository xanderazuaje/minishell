/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/02 01:27:30 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"
#include <errno.h>

void process_line(char **line)
{
	(void) line;
	/*
	char *result;
	result = asterix_expander(*line);
	free(result);
	exit(0);
	 */
}


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
		if (!line || ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			write(1, "bai\n", 4);
			exit(exit_status);
		}
		cmds = parse_str(line, env);
//		for (t_cmdlist *node = cmds; node; node = node->next)
//			printf("%s\n", node->word);
		if (!cmds)
			continue ;
		executor(cmds);
		free_cmd(cmds);
	}
}
