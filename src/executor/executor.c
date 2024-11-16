/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:48:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/16 20:22:42 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	set_hdocs(t_cmdlist *list, char **env, int **hdoc_pipes)
{
	int	count;

	count = count_processes(list);
	*hdoc_pipes = (int *) safe_malloc(count * sizeof(int));
	ft_memset(*hdoc_pipes, -1, count * sizeof(int));
	assign_hdocs(list, *hdoc_pipes, env);
}

char	**set_cmd_args(t_cmdlist *list, char **env, char **cmd)
{
	int		i;
	int		count;
	char	**arg_list;

	i = 0;
	count = count_args(list);
	arg_list = (char **)safe_malloc((count + 1) * sizeof (char *));
	while (list && list->flags != pipe_flag)
	{
		if (list->flags == argument || list->flags == command)
		{
			if (*cmd == NULL)
				*cmd = expand_path(list->word, env);
			arg_list[i] = list->word;
			i++;
		}
		list = list->next;
	}
	arg_list[i] = NULL;
	return (arg_list);
}

void	execute_it(char **env, char **arg_list, char *cmd)
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
		if (arg_list[0] != NULL)
		{
			write(2, arg_list[0], strlen(arg_list[0]));
			write(2, ": command not found\n", 20);
		}
		exit(127);
	}
}

int	is_builtin(char **arg_list)
{
	if (arg_list && arg_list[0])
	{
		if (ft_strncmp(arg_list[0], "env", 4) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "pwd", 4) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "exit", 5) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "cd", 3) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "echo", 5) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "export", 7) == 0)
			return (1);
		if (ft_strncmp(arg_list[0], "unset", 6) == 0)
			return (1);
		return (0);
	}
	return (0);
}

void	executor(t_cmdlist *list, char ***env)
{
	t_cmd	command;
	t_exec	exec;
	char	*first_command;

	exec.i = 0;
	exec.cmd_count = count_processes(list);
	set_hdocs(list, *env, &exec.hdoc_pipes);
	command.cmd = NULL;
	first_command = get_first_command(list);
	while (list)
	{
		separate_process(list, env, &command, &exec);
		do_process(list, env, command, &exec);
		close(exec.hdoc_pipes[exec.i]);
		free(command.cmd);
		command.cmd = NULL;
		free(command.arg_list);
		list = next_cmd(list);
		exec.i++;
	}
	if (exec.cmd_count > 1)
		close(exec.pipes_fd[1][RD_PIPE]);
	if (!is_builtin(&first_command) || exec.cmd_count > 1)
		wait_children();
	free(exec.hdoc_pipes);
}
