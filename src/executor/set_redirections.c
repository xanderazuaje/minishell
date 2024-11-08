/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:57:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 14:03:35 by xazuaje-         ###   ########.fr       */
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

void	set_redirections(t_cmdlist *l, const int *hdp, const int i, char **env)
{
	char	*lts_cmd;

	lts_cmd = find_command(l);
	while (l && l->flags != pipe_flag)
	{
		if (l->flags == command)
			lts_cmd = l->word;
		if (l->flags == infile)
			set_infile(l, env);
		else if (l->flags == here_document)
		{
			if (!is_builtin(&lts_cmd))
				set_hdoc(hdp, i);
			else
				close(hdp[i]);
		}
		else if (l->flags == outfile)
			set_outfile(l, env);
		else if (l->flags == append_outfile)
			set_append_outfile(l, env);
		l = l->next;
	}
}
