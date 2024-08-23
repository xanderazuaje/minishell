/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:57:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 19:49:28 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"
#include "../parsing/expansor/_expansor.h"

int	set_infile(t_cmdlist *list, int *fd, char **env)
{
	char	*file_name;

	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDIN_FILENO) < 0)
		perror(file_name);
	close(*fd);
	free(file_name);
	return (1);
}

int	set_outfile(t_cmdlist *list, int *fd, char **env)
{
	char	*file_name;
	char	*var_name;

	var_name = ft_strdup(list->next->word);
	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, var_name, ft_strlen(var_name));
		free(var_name);
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	*fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(*fd);
	free(file_name);
	free(var_name);
	return (1);
}

int	set_append_outfile(t_cmdlist *list, int *fd, char **env)
{
	char	*file_name;

	file_name = expand_var(list->next->word, env, prev_exit_status(0));
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	*fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (*fd < 0)
	{
		perror(file_name);
		return (0);
	}
	if (dup2(*fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(*fd);
	free(file_name);
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

int	set_redirections(t_cmdlist *list, const int *hdoc_pipes, const int i, char **env)
{
	int	fd;
	int	value;

	while (list && list->flags != pipe_flag)
	{
		if (list->flags == infile)
			value = set_infile(list, &fd, env);
		else if (list->flags == here_document)
			value = set_hdoc(hdoc_pipes, i);
		else if (list->flags == outfile)
			value = set_outfile(list, &fd, env);
		else if (list->flags == append_outfile)
			value = set_append_outfile(list, &fd, env);
		else
			value = 1;
		if (value == 0)
			return (0);
		list = list->next;
	}
	return (1);
}
