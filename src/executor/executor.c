/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:27:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 06:47:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void set_hdocs(t_cmdlist *list, char **env, int **hdoc_pipes)
{
	int		count;

	count = count_processes(list);
	*hdoc_pipes = (int *) safe_malloc(count * sizeof(int));
	ft_memset(*hdoc_pipes, -1, count * sizeof(int));
	assign_hdocs(list, *hdoc_pipes, env);
}

char **set_cmd_args(t_cmdlist *list, char **env, char **cmd)
{
	int		i;
	int		count;
	char	**arg_list;

	i = 0;
	count = count_args(list);
	arg_list = (char **) safe_malloc((count + 1) * sizeof(char*));
	while (list && list->flags != pipe_flag)
	{
		if (list->flags == argument || list->flags == command)
		{
			if (list->flags == command)
				*cmd = expand_path(list->word, env);
			arg_list[i] = list->word;
			i++;
		}
		list = list->next;
	}
	arg_list[i] = NULL;
	return (arg_list);
}

void execute_it(char **env, char **arg_list, char *cmd)
{
	if (cmd != NULL)
	{
		if (execve(cmd, arg_list, env) == -1)
		{
			perror(arg_list[0]);
			exit(127);
		}
	}
	else
	{
		write(2,  arg_list[0], strlen(arg_list[0]));
		write(2,  ": command not found\n", 20);
		exit(127);
	}
}

int set_redirections(t_cmdlist *list, int *hdoc_pipes, int i)
{
	int	fd;
	char *file_name;

	while (list)
	{
		if (list->flags == infile)
		{
			file_name = list->next->word;
			fd = open(file_name, O_RDONLY);
			if (fd < 0)
			{
				perror(file_name);
				return (0);
			}
			if (dup2(fd, STDIN_FILENO) < 0)
				perror(file_name);
			close(fd);
		}
		else if (list->flags == here_document)
		{
			if (dup2(hdoc_pipes[i], STDIN_FILENO) < 0)
				perror("here document");
			close(hdoc_pipes[i]);
		}
		else if (list->flags == outfile)
		{
			file_name = list->next->word;
			fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				perror(file_name);
				return (0);
			}
			if (dup2(fd, STDOUT_FILENO) < 0)
				perror(file_name);
			close(fd);
		}
		else if (list->flags == append_outfile)
		{
			file_name = list->next->word;
			fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (fd < 0)
			{
				perror(file_name);
				return (0);
			}
			if (dup2(fd, STDOUT_FILENO) < 0)
				perror(file_name);
			close(fd);
		}
		list = list->next;
	}
	return (1);
}

t_cmdlist *next_cmd(t_cmdlist *list)
{
	while (list)
	{
		if (list->flags == pipe_flag)
			return (list->next);
		list = list->next;
	}
	return (list);
}

void	executor(t_cmdlist *list, char **env)
{
	char	**arg_list;
	int		*hdoc_pipes;
	char	*cmd;
	int		exit_status;
	int		i;

	i = 0;
	set_hdocs(list, env, &hdoc_pipes);
	while (list)
	{
		arg_list = set_cmd_args(list, env, &cmd);
		if (fork() == 0)
		{
			if (set_redirections(list, hdoc_pipes, i))
				execute_it(env, arg_list, cmd);
			exit(1);
		}
		free(cmd);
		free(arg_list);
		list = next_cmd(list);
		i++;
	}
	while (waitpid(-1, &exit_status, 0) != -1)
	{}
	prev_exit_status(exit_status);
	/*last*/
	free(hdoc_pipes);
}
