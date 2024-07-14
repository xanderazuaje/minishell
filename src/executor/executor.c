/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:27:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/13 14:27:50 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	executor(t_cmdlist *list, char **env)
{
	char	**arg_list;
	int		*hdoc_pipes;
	int		count;
	char	*cmd;
	int		i;

	i = 0;
	count = count_processes(list);
	hdoc_pipes = (int *) ft_calloc(count, sizeof(int));
	if (hdoc_pipes == NULL)
	{
		perror("malloc:");
		exit(1);
	}
	assign_hdocs(list, hdoc_pipes, env);
	varg_set_null(2, &arg_list);
	count = count_args(list);
	arg_list = (char **) safe_malloc((count + 1) * sizeof(char*));
	while (list && list->flags != pipe_flag)
	{
		if (list->flags == argument || list->flags == command)
		{
			if (list->flags == command)
				cmd = expand_path(list->word, env);
			arg_list[i] = list->word;
			i++;
		}
		list = list->next;
	}
	arg_list[i] = NULL;
	if (cmd != NULL)
		execve(cmd, arg_list, env);
	else
	{
		write(2,  "command not found\n", 18);
	}
	/*last*/
	free(hdoc_pipes);
	free(arg_list);
}