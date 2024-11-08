/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:58:57 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 13:51:11 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	is_redir(t_flags c)
{
	return (c == outfile || c == append_outfile || c == infile);
}

int	has_command(const t_cmdlist *cmdlist)
{
	while (cmdlist && ft_strncmp(cmdlist->word, "|", 2) != 0)
	{
		if (cmdlist->flags == command)
			return (1);
		cmdlist = cmdlist->next;
	}
	return (0);
}

void	set_command_or_argument(const t_cmdlist *cmdlist, t_flags *curr)
{
	if (!has_command(cmdlist))
		*curr = command;
	else
		*curr = argument;
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
	else if ((*prev) == command || (*prev) == argument)
		*curr = argument;
	else if ((*prev) == init || (*prev) == pipe_flag)
		*curr = command;
	else if (is_redir((*prev)))
		*curr = file_name;
	else if (*prev == file_name || *prev == here_document_limit)
		set_command_or_argument(cmdlist, curr);
	else if (*prev == here_document)
		*curr = here_document_limit;
	else if (*prev == here_document_limit)
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
