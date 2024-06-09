/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:44 by xander            #+#    #+#             */
/*   Updated: 2024/06/05 05:28:46 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"
#include <errno.h>

/*
void test_splitted(char **line)
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
}*/

void test_expansor(char **line)
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
	expand(splitted, NULL);
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

void process_line(char **line)
{
	printf("%s\n", *line);
	exit(0);
}

int main(int argc, char **argv, char **env)
{
	char *line;
	pid_t child_id;
	int exit_status;

	exit_status = 0;
	printf("%s\n", argv[argc - 1]);
	(void ) env;
	while (1)
	{
		line = readline("Santishell> ");
		if (line)
			add_history(line);
		if (ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			exit(exit_status);
		}
		child_id = fork();
		if (child_id == 0)
			test_expansor(&line);
		waitpid(child_id, &exit_status, 0);
		printf("%i\n", WEXITSTATUS(exit_status));
		free(line);
	}
}
