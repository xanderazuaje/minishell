/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expansor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:58:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/16 03:22:51 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	test_expansor(char **line, char **env)
{
	size_t		i;
	t_cmdlist	*splitted;
	t_cmdlist	*temp;

	i = 0;
	splitted = expand(*line, env);
	temp = splitted;
	while (temp)
	{
		printf("--------\n");
		if (temp->word)
			printf("%s\n", temp->word);
		temp = temp->next;
		i++;
	}
	free_cmd(splitted);
	exit((int) i);
}
