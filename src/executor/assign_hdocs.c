/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hdocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:19:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/13 15:19:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	assign_hdocs(t_cmdlist *list, int *hdoc_pipes, char **env)
{
	int		i;
	int		pipe_fd[2];
	char	*line;

	i = 0;
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	while (list)
	{
		if (list->flags == here_document)
		{
			line = (char *)malloc(sizeof (char));
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			if (pipe(pipe_fd) == -1)
			{
				perror("error:");
				return ;
			}
			here_doc(list, env, pipe_fd, &line);
			close(pipe_fd[WR_PIPE]);
			hdoc_pipes[i] = pipe_fd[RD_PIPE];
			free(line);
		}
		else if (list->flags == pipe_flag)
			i++;
		list = list->next;
	}
}
