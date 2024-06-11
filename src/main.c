/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:57 by xazuaje-         ###   ########.fr       */
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

void test_expansor(char **line, char **env)
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
	expand(splitted, env);
	while (splitted)
	{
		printf("--------\n");
		if (splitted->word)
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
			test_expansor(&line, env);
		waitpid(child_id, &exit_status, 0);
		printf("%i\n", WEXITSTATUS(exit_status));
		free(line);
	}
}
