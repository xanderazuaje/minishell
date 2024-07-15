/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:57:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 06:58:33 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

int	set_infile(t_cmdlist *list, int *fd)
{
	char	*file_name;

	file_name = list->next->word;
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDIN_FILENO) < 0)
		perror(file_name);
	close(*fd);
	return (1);
}

int	set_outfile(t_cmdlist *list, int *fd)
{
	char	*file_name;

	file_name = list->next->word;
	*fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(*fd);
	return (1);
}

int	set_append_outfile(t_cmdlist *list, int *fd)
{
	char	*file_name;

	file_name = list->next->word;
	*fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(*fd);
	return (1);
}

int	set_hdoc(const int *hdoc_pipes, const int i)
{
	if (dup2(hdoc_pipes[i], STDIN_FILENO) < 0)
	{
		perror("here document");
		return (0);
	}
	close(hdoc_pipes[i]);
	return (1);
}

int	set_redirections(t_cmdlist *list, const int *hdoc_pipes, const int i)
{
	int	fd;
	int	value;

	while (list)
	{
		if (list->flags == infile)
			value = set_infile(list, &fd);
		else if (list->flags == here_document)
			value = set_hdoc(hdoc_pipes, i);
		else if (list->flags == outfile)
			value = set_outfile(list, &fd);
		else if (list->flags == append_outfile)
			value = set_append_outfile(list, &fd);
		else
			value = 1;
		if (value == 0)
			return (0);
		list = list->next;
	}
	return (1);
}
