/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:00:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/19 20:56:09 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

int	set_infile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int		fd;

	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror(file_name), free(file_name), 0);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (perror(file_name), free(file_name), 0);
	close(fd);
	free(file_name);
	return (1);
}

int	set_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int		fd;

	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror(file_name), free(file_name), 0);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (perror(file_name), free(file_name), 0);
	close(fd);
	free(file_name);
	return (1);
}

int	set_append_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int		fd;

	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return (0);
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (perror(file_name), free(file_name), 0);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (perror(file_name), free(file_name), 0);
	close(fd);
	free(file_name);
	return (1);
}
