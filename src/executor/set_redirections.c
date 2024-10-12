/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:57:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/12 09:56:13 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"
#include "../parsing/expansor/_expansor.h"

void	set_infile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int fd;

	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return;
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(file_name);
		return;
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		perror(file_name);
	close(fd);
	free(file_name);
}

void set_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	char	*var_name;
	int		fd;

	var_name = ft_strdup(list->next->word);
	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, var_name, ft_strlen(var_name));
		free(var_name);
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return;
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return;
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(fd);
	free(var_name);
}

void	set_append_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int fd;

	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return;
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return;
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(fd);
}

void	set_hdoc(const int *hdoc_pipes, const int i)
{
	if (dup2(hdoc_pipes[i], STDIN_FILENO) < 0)
	{
		perror("here document");
		return;
	}
	close(hdoc_pipes[i]);
}

void set_redirections(t_cmdlist *list, const int *hdoc_pipes, const int i, char **env)
{
	while (list && list->flags != pipe_flag)
	{
		if (list->flags == infile)
			set_infile(list, env);
		else if (list->flags == here_document)
			set_hdoc(hdoc_pipes, i);
		else if (list->flags == outfile)
			set_outfile(list, env);
		else if (list->flags == append_outfile)
			set_append_outfile(list, env);
		list = list->next;
	}
	return;
}
