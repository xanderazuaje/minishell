/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/25 01:28:24 by xazuaje-         ###   ########.fr       */
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
	printf("%s\n", argv[argc - 1]);
	(void ) env;
	while (1)
	{
		line = readline("\033[0;33mbASSh> \033[0;0m");
		if (line && *line)
			add_history(line);
		if (ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			write(1, "bai\n", 4);
			exit(exit_status);
		}
		cmds = parse_str(line, env);
		if (!cmds)
			continue ;
		for (t_cmdlist *command = cmds; command != NULL ;command = command->next)
		{
			if (command->word)
				printf("%s\n", command->word);
			printf("id: %d\n", command->flags);
			printf("-------\n");
		}
		free_cmd(cmds);
	}
}
