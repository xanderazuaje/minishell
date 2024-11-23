/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:57:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/19 21:12:39 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	set_hdoc(const int *hdoc_pipes, const int i)
{
	dup2(hdoc_pipes[i], STDIN_FILENO);
	close(hdoc_pipes[i]);
}

char	*find_command(t_cmdlist *l)
{
	while (l)
	{
		if (l->flags == command)
			return (l->word);
		l = l->next;
	}
	return (NULL);
}

void	set_child_hdoc(const int *hdp, const int i, char *lts_cmd)
{
	if (!is_builtin(&lts_cmd))
		set_hdoc(hdp, i);
	else
		close(hdp[i]);
}

int	set_redirections(t_cmdlist *l, const int *hdp, const int i, char **env)
{
	char	*lts_cmd;
	int		status;

	lts_cmd = find_command(l);
	status = 1;
	while (l && l->flags != pipe_flag)
	{
		if (l->flags == command)
			lts_cmd = l->word;
		if (l->flags == infile)
			status = set_infile(l, env, lts_cmd);
		else if (l->flags == here_document)
			set_child_hdoc(hdp, i, lts_cmd);
		else if (l->flags == outfile)
			status = set_outfile(l, env);
		else if (l->flags == append_outfile)
			status = set_append_outfile(l, env);
		l = l->next;
		if (status == 0)
			return (status);
	}
	return (status);
}
