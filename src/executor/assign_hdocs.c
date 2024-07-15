/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hdocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:19:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 07:21:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

int	assign_single_hdoc(t_cmdlist *list, int *hdoc_pipes, char **env, int i)
{
	char	*line;
	int		pipe_fd[2];

	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	line = (char *)malloc(sizeof (char));
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (pipe(pipe_fd) == -1)
	{
		perror("error:");
		return (0);
	}
	here_doc(list, env, pipe_fd, &line);
	close(pipe_fd[WR_PIPE]);
	hdoc_pipes[i] = pipe_fd[RD_PIPE];
	free(line);
	return (1);
}

void	assign_hdocs(t_cmdlist *list, int *hdoc_pipes, char **env)
{
	int		i;

	i = 0;
	while (list)
	{
		if (list->flags == here_document)
		{
			if (!assign_single_hdoc(list, hdoc_pipes, env, i))
				return ;
		}
		else if (list->flags == pipe_flag)
			i++;
		list = list->next;
	}
}
