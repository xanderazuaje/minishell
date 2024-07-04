/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:27:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/02 01:46:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

char	**set_arg_list(t_cmdlist *list)
{
	char		**arg_list;
	t_cmdlist	*temp;
	int			i;

	i = 0;
	temp = list;
	while (temp && temp->flags != pipe_flag)
	{
		if (temp->flags == command || temp->flags == argument)
			i++;
		temp = temp->next;
	}
	arg_list = (char **) safe_malloc(sizeof (char *) * (i + 1));
	temp = list;
	i = 0;
	while (temp && temp->flags != pipe_flag)
	{
		if (temp->flags == command || temp->flags == argument)
		{
			if (!temp->word)
				arg_list[i] = ft_strdup("");
			else
				arg_list[i] = ft_strdup(temp->word);
			i++;
		}
		temp = temp->next;
	}
	arg_list[i] = NULL;
	return arg_list;
}

void	open_files(t_cmdlist *list, int *in, int *out)
{
	int in2;
	int out2;
	char *line;
	char *limit;
	int hdoc_pipes[2];

	while (list)
	{
		if (list->flags == infile)
		{
			list = list->next;
			in2 = open(list->word, O_RDONLY);
			if (in2 < 0)
			{
				perror(list->word);
				exit(1);
			}
			dup2(*in, in2);
			close(*in);
			*in = in2;
		}
		else if (list->flags == here_document)
		{
			list = list->next;
			limit = ft_strjoin(list->word, "\n");
			if (pipe(hdoc_pipes) == -1)
				exit(1);
			while (1)
			{
				line = readline(">");
				if (ft_strncmp(limit, line, ft_strlen(limit)) == 0)
				{
					free(line);
					break;
				}
				write(hdoc_pipes[WR_PIPE], line, ft_strlen(line));
				free(line);
			}
			free(limit);
			if (dup2(hdoc_pipes[RD_PIPE], STDIN_FILENO) == -1)
			{
				close(hdoc_pipes[RD_PIPE]);
				perror("here document");
			}
			close(here_document);
		}
		else if (list->flags == outfile)
		{
			list = list->next;
			out2 = open(list->word, O_RDWR | O_CREAT | O_TRUNC, 0644);
			dup2(*out, out2);
			close(*out);
			*out= out2;
		}
		else if (list->flags == append_outfile)
		{
			list = list->next;
			out2 = open(list->word, O_RDWR | O_CREAT | O_APPEND, 0644);
			dup2(*out, out2);
			close(*out);
			*out= out2;
		}
		list = list->next;
	}
}

void	executor(t_cmdlist *list)
{
	char	**arg_list;
	char	*cmd;
	int		fd[2];

	varg_set_null(2, &arg_list, &cmd);
	open_files(list, &fd[0], &fd[1]);
	arg_list = set_arg_list(list);
	cmd = arg_list[0];
	while (*arg_list)
	{
		printf("%s\n", *arg_list);
		free(*arg_list);
		arg_list++;
	}
}