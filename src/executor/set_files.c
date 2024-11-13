/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:00:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/13 19:39:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	set_infile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int		fd;

	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return ;
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(file_name);
		return ;
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		perror(file_name);
	close(fd);
	free(file_name);
}

void	set_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	char	*var_name;
	int		fd;

	var_name = ft_strdup(list->next->word);
	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, var_name, ft_strlen(var_name));
		free(var_name);
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return ;
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(fd);
	free(var_name);
}

void	set_append_outfile(t_cmdlist *list, char **env)
{
	char	*file_name;
	int		fd;

	file_name = expand_var(list->next->word, env);
	if (!file_name || ft_strrchr(file_name, ' ') != 0)
	{
		write(2, list->next->word, ft_strlen(list->next->word));
		write(2, ": ambiguous redirect\n", 21);
		free(file_name);
		return ;
	}
	fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror(file_name);
	close(fd);
}
