/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 17:40:10 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "../minishell.h"

void exec_builtin(char **args, char ***env);

//void do_cd(char **args);
void do_pwd(void);
void do_exit(char **args, char ***env);
void do_env(char **envp);
int do_cd(char **args, char **envcopy);
int do_echo(char **args);
int do_export(char **args, char ***env);
int do_unset(char **args, char **env);
//utils
int envlen(char **env);
void    free_array(char **arr);
char **copy_env(char **env);
void printenv(char **envcopy);

#endif