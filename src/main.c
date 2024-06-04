/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:44 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 03:46:28 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"
#include <errno.h>

void process_line(char **line)
{
	size_t i;
	t_cmdlist	*splitted;
	t_cmdlist	*temp;

	i = 0;
	splitted = split_sh(*line);
	if (!splitted)
	{
		perror("readline:");
		exit(EXIT_FAILURE);
	}
	temp = splitted;
	while (splitted)
	{
		printf("--------\n");
		printf("%s\n", splitted->word);
		splitted = splitted->next;
		i++;
	}
	free_cmd(temp);
	free(*line);
	exit((int) i);
}

int main()
{
	char *line;
	pid_t child_id;
	int exit_status;

	exit_status = 0;
	while (1)
	{
		line = readline("Ulishell> ");
		if (line)
			add_history(line);
		if (ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			exit(exit_status);
		}
		child_id = fork();
		if (child_id == 0)
			process_line(&line);
		waitpid(child_id, &exit_status, 0);
		printf("%i\n", WEXITSTATUS(exit_status));
		free(line);
	}
}
