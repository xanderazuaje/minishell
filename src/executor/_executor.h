/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:48:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 19:57:21 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXECUTOR_H
# define _EXECUTOR_H

# define WR_PIPE 1
# define RD_PIPE 0
# include "../types.h"
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../minishell.h"

void	executor(t_cmdlist *list, char **env);
char	*expand_hdoc(char *str, char **env);
int		count_processes(const t_cmdlist *list);
int		count_args(const t_cmdlist *list);
void	here_doc(t_cmdlist *list, char **env, int pipe_fd[2], char **line);
void	assign_hdocs(t_cmdlist *list, int *hdoc_pipes, char **env);
char	*expand_path(const char *program, char **env);
int		set_redirections(t_cmdlist *list, const int *hdoc_pipes, const int i, char **env);

#endif
