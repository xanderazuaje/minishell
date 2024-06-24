/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/24 16:32:55 by xazuaje-         ###   ########.fr       */
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
	pid_t child_id;
	int exit_status;

	(void) env;
	exit_status = 0;
	printf("%s\n", argv[argc - 1]);
	(void ) env;
	while (1)
	{
		line = readline("\033[0;33mbASSh> \033[0;0m");
		if (line)
			add_history(line);
		if (ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			write(1, "bai\n", 4);
			exit(exit_status);
		}
		child_id = fork();
		if (child_id == 0)
			test_lexer(line);
		waitpid(child_id, &exit_status, 0);
		printf("%i\n", WEXITSTATUS(exit_status));
		free(line);
	}
}
