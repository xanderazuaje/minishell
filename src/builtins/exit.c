/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:33:47 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 14:17:05 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	exit_error(char *str)
{
	write(2, "exit: ", 6);
	ft_putstr_fd(str, 2);
	write(2, ": numeric argument required\n", 28);
}

void	check_valid_input(char **args, int i)
{
	if (args[1][i] != '\0')
	{
		exit_error(args[1]);
		g_exit_status = 2;
	}
	if (args[2])
	{
		write(2, "exit: too many arguments\n", 26);
		g_exit_status = 1;
	}
	else
		g_exit_status = ft_atoi(args[1]) % 256;
}

void	do_exit(char **args, char ***env)
{
	int	i;

	i = 0;
	if (args[1])
	{
		while (args[1][i] && (ft_isdigit(args[1][i])
			|| (i == 0 && args[1][i] == '-')))
			i++;
		check_valid_input(args, i);
	}
	freeenv(env);
	exit(g_exit_status);
}
