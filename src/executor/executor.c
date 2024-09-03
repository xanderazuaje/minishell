/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:27:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/09/03 12:36:10 by mhiguera         ###   ########.fr       */
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
		if (arg_list[0] != NULL)
			write(2,  arg_list[0], strlen(arg_list[0]));
		write(2,  ": command not found\n", 20);
		exit(127);
	}
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

void wait_children()
{
	int		exit_status;

	while (waitpid(-1, &exit_status, 0) != -1)
	{}
	prev_exit_status(exit_status);
}

void set_pipes(t_cmdlist *list, int i, int pipes_fd[2][2])
{
	if (i > 0 || next_cmd(list))
	{
		if (i == 0)
		{
			dup2(pipes_fd[0][WR_PIPE], STDOUT_FILENO);
			close(pipes_fd[0][WR_PIPE]);
			close(pipes_fd[0][RD_PIPE]);
		}
		else if (next_cmd(list) == NULL)
		{
			dup2(pipes_fd[1][RD_PIPE], STDIN_FILENO);
			close(pipes_fd[1][WR_PIPE]);
			close(pipes_fd[1][RD_PIPE]);
		}
		else
		{
			dup2(pipes_fd[0][WR_PIPE], STDOUT_FILENO);
			close(pipes_fd[0][WR_PIPE]);
			close(pipes_fd[0][RD_PIPE]);
			dup2(pipes_fd[1][RD_PIPE], STDIN_FILENO);
			close(pipes_fd[1][WR_PIPE]);
			close(pipes_fd[1][RD_PIPE]);
		}
	}
}

int is_builtin(char **arg_list)
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
		return (0);
	}
	return (0);
}

void	executor(t_cmdlist *list, char **env)
{
	t_cmd	command;
	int		*hdoc_pipes;
	int		i;
	int		pipes_fd[2][2];
	int		cmd_count;

	i = 0;
	cmd_count = count_processes(list);
	set_hdocs(list, env, &hdoc_pipes);
	command.cmd = NULL;
	while (list)
	{
		if (next_cmd(list))
			pipe(pipes_fd[0]);
		command.arg_list = set_cmd_args(list, env, &(command.cmd));
		if (cmd_count > 1 || !is_builtin(command.arg_list))
		{
			if (fork() == 0)
			{
				set_pipes(list, i, pipes_fd);
				if (set_redirections(list, hdoc_pipes, i, env))
				{
					if (is_builtin(command.arg_list))
						exec_builtin(command.arg_list, env);
					else
						execute_it(env, command.arg_list, command.cmd);
				}
				exit(1);
			}
			if (cmd_count > 1)
			{
				close(pipes_fd[0][WR_PIPE]);
				pipes_fd[1][WR_PIPE] = pipes_fd[0][WR_PIPE];
				pipes_fd[1][RD_PIPE] = pipes_fd[0][RD_PIPE];
			}
		}
		else if (is_builtin(command.arg_list))
			exec_builtin(command.arg_list, env);
		close(hdoc_pipes[i]);
		free(command.cmd);
		command.cmd = NULL;
		free(command.arg_list);
		list = next_cmd(list);
		i++;
	}
	if (cmd_count > 1)
		close(pipes_fd[1][RD_PIPE]);
	wait_children();
	/*last*/
	free(hdoc_pipes);
}
