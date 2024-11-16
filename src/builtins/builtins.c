/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/02 11:44:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_builtin(char **args, char ***env)
{
	if (ft_strncmp(args[0], "env", 4) == 0)
		return (do_env(*env));
	if (ft_strncmp(args[0], "pwd", 4) == 0)
		return (do_pwd());
	if (ft_strncmp(args[0], "exit", 5) == 0)
		return (do_exit(args, env));
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (do_cd(args, *env));
	if (ft_strncmp(args[0], "echo", 5) == 0)
		return (do_echo(args));
	if (ft_strncmp(args[0], "export", 7) == 0)
		return (do_export(args, env));
	if (ft_strncmp(args[0], "unset", 6) == 0)
		return (do_unset(args, *env));
	return (0);
}
