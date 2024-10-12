/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:58:57 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 22:35:11 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	is_redir(t_flags c)
{
	return (c == outfile || c == append_outfile || c == infile);
}

void	get_flag_state(const t_cmdlist *cmdlist, t_flags *prev, t_flags *curr)
{
	if (ft_strncmp(cmdlist->word, "|", ft_strlen(cmdlist->word)) == 0)
		*curr = pipe_flag;
	else if (ft_strncmp(cmdlist->word, ">", ft_strlen(cmdlist->word)) == 0)
		*curr = outfile;
	else if (ft_strncmp(cmdlist->word, ">>", ft_strlen(cmdlist->word)) == 0)
		*curr = append_outfile;
	else if (ft_strncmp(cmdlist->word, "<", ft_strlen(cmdlist->word)) == 0)
		*curr = infile;
	else if (ft_strncmp(cmdlist->word, "<<", ft_strlen(cmdlist->word)) == 0)
		*curr = here_document;
	else if ((*prev) == command || (*prev) == argument || *prev == file_name)
		*curr = argument;
	else if ((*prev) == init || (*prev) == pipe_flag)
		*curr = command;
	else if (is_redir((*prev)))
		*curr = file_name;
	else if ((*prev) == here_document)
		*curr = here_document_limit;
	else if ((*prev) == here_document_limit)
		*curr = argument;
}

void	tokenizer(t_cmdlist *cmdlist)
{
	t_flags	prev;
	t_flags	curr;

	prev = init;
	curr = init;
	while (cmdlist)
	{
		get_flag_state(cmdlist, &prev, &curr);
		cmdlist->flags = curr;
		prev = curr;
		cmdlist = cmdlist->next;
	}
}
