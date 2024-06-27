/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:57:37 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 12:58:53 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	test_splitted(char **line)
{
	size_t		i;
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
