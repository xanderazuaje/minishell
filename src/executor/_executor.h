/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:48:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/19 21:51:29 by xazuaje-         ###   ########.fr       */
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
# include "../parsing/expansor/_expansor.h"

void		executor(t_cmdlist *list, char ***env);
char		*expand_hdoc(char *str, char **env);
int			count_processes(const t_cmdlist *list);
int			count_args(const t_cmdlist *list);
void		here_doc(t_cmdlist *list, char **env, int pipe_fd[2], char **line);
void		assign_hdocs(t_cmdlist *list, int *hdoc_pipes, char **env);
char		*expand_path(const char *program, char **env);
int			set_redirections(t_cmdlist *l, const int *hdp, int i, char **env);
t_cmdlist	*next_cmd(t_cmdlist *list);
void		wait_children(void);
void		set_pipes(t_cmdlist *list, int i, int pipes_fd[2][2]);
int			is_builtin(char **arg_list);
void		child_process(t_cmdlist *list, char ***env, t_cmd c, t_exec *e);
void		pipe_cmd(t_cmdlist *list, char ***env, t_cmd c, t_exec *e);
void		execute_it(char **env, char **arg_list, char *cmd);
int			separate_process(t_cmdlist *list, char ***env, t_cmd *c, t_exec *e);
char		**set_cmd_args(t_cmdlist *list, char **env, char **cmd);
void		do_process(t_cmdlist *list, char ***env, t_cmd c, t_exec *e);
int			set_infile(t_cmdlist *list, char **env, char *lts_cmd);
int			set_outfile(t_cmdlist *list, char **env);
int			set_append_outfile(t_cmdlist *list, char **env);
char		*get_first_command(t_cmdlist *list);

#endif
