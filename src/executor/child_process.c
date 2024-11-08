/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:17:21 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/04 14:43:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	child_process(t_cmdlist *list, char ***env, t_cmd c, t_exec *e)
{
	set_pipes(list, e->i, e->pipes_fd);
	set_redirections(list, e->hdoc_pipes, e->i, *env);
	if (is_builtin(c.arg_list))
		exec_builtin(c.arg_list, env);
	else
		execute_it(*env, c.arg_list, c.cmd);
	exit(1);
}

void	pipe_cmd(t_cmdlist *list, char ***env, t_cmd c, t_exec *e)
{
	if (fork() == 0)
		child_process(list, env, c, e);
	if (e->cmd_count > 1)
	{
		close(e->pipes_fd[0][WR_PIPE]);
		e->pipes_fd[1][WR_PIPE] = e->pipes_fd[0][WR_PIPE];
		e->pipes_fd[1][RD_PIPE] = e->pipes_fd[0][RD_PIPE];
	}
}

void	separate_process(t_cmdlist *list, char ***env, t_cmd *c,
	t_exec *e)
{
	if (next_cmd(list))
		pipe(e->pipes_fd[0]);
	c->arg_list = set_cmd_args(list, *env, &c->cmd);
	if (e->cmd_count == 1 && is_builtin(c->arg_list))
	{
		e->saved_stdout = dup(STDOUT_FILENO);
		set_redirections(list, e->hdoc_pipes, e->i, *env);
	}
}

void	do_process(t_cmdlist *list, char ***env, t_cmd c, t_exec *e)
{
	if (e->cmd_count > 1 || !is_builtin(c.arg_list))
		pipe_cmd(list, env, c, e);
	else if (is_builtin(c.arg_list))
	{
		exec_builtin(c.arg_list, env);
		dup2(e->saved_stdout, STDOUT_FILENO);
		close(e->saved_stdout);
	}
}
