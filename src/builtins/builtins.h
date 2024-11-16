/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/16 19:21:33 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../minishell.h"

int	exec_builtin(char **args, char ***env);

int	do_pwd(void);
int	do_exit(char **args, char ***env);
int	do_env(char **envp);
int	do_cd(char **args, char **envcopy);
int	do_echo(char **args);
int	do_export(char **args, char ***env);
int	do_unset(char **args, char **env);
int	envlen(char **env);

#endif