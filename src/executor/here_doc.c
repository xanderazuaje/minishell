/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:32:16 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/13 15:26:13 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	hdoc_eof_error(int count, char *limit)
{
	char *count_str;

	count_str = ft_itoa(count);
	write(2, "warning: here-document at line ", 31);
	write(2, count_str, ft_strlen(count_str));
	write(2, " delimited by end-of-file (wanted '", 35);
	write(2, limit, ft_strlen(limit));
	write(2, "')\n", 3);
	free(count_str);
}

int	must_expand(const t_cmdlist *list)
{
	return ft_strchr(list->word, '\'') == NULL ||
	       ft_strchr(list->word, '"') == NULL;
}

int	try_write(int pipe_fd[2], const char *line)
{
	if (write(pipe_fd[WR_PIPE], line, ft_strlen(line)) == -1)
	{
		perror("error:");
		return (0);
	}
	return (1);
}

void	here_doc(t_cmdlist *list, char **env, int pipe_fd[2], char **line)
{
	char				*tmp;
	char				*limit;
	static unsigned int	count = 1;

	limit = expand_quotes(list->next->word);
	while (count++)
	{
		tmp = *line;
		*line = readline(">");
		free(tmp);
		if (!*line)
		{
			hdoc_eof_error(count, limit);
			break;
		}
		if (ft_strncmp(*line, limit, ft_strlen(limit)) == 0)
			break;
		if (ft_strchr(*line, '$') && must_expand(list->next))
			*line = expand_hdoc(*line, env);
		if (!try_write(pipe_fd, *line))
			break;
	}
	free(limit);
}
