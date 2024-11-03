/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:49:52 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/03 10:25:19 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

t_cmdlist	*next_cmd(t_cmdlist *list)
{
	while (list)
	{
		if (list->flags == pipe_flag)
			return (list->next);
		list = list->next;
	}
	return (list);
}

void	wait_children(void)
{
	int	exit_status;

	while (waitpid(-1, &exit_status, 0) != -1)
	{
	}
	prev_exit_status(exit_status);
}

void	set_pipes(t_cmdlist *list, int i, int pipes_fd[2][2])
{
	if (i > 0 || next_cmd(list))
	{
		if (i == 0)
		{
			dup2(pipes_fd[0][WR_PIPE], STDOUT_FILENO);
			close(pipes_fd[0][WR_PIPE]);
			close(pipes_fd[0][RD_PIPE]);
		}
		else if (next_cmd(list) == NULL)
		{
			dup2(pipes_fd[1][RD_PIPE], STDIN_FILENO);
			close(pipes_fd[1][WR_PIPE]);
			close(pipes_fd[1][RD_PIPE]);
		}
		else
		{
			dup2(pipes_fd[0][WR_PIPE], STDOUT_FILENO);
			close(pipes_fd[0][WR_PIPE]);
			close(pipes_fd[0][RD_PIPE]);
			dup2(pipes_fd[1][RD_PIPE], STDIN_FILENO);
			close(pipes_fd[1][WR_PIPE]);
			close(pipes_fd[1][RD_PIPE]);
		}
	}
}
