/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:45:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/15 23:37:57 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "globals.h"

void	prev_exit_status(int i)
{
	if (WIFSIGNALED(i))
	{
		g_exit_status = 128 + WTERMSIG(i);
		if (WTERMSIG(i) == SIGQUIT)
			write(2, "Core dump\n", 11);
		else if (WTERMSIG(i) == SIGINT)
			write(2, "\n", 1);
	}
	else if (WIFEXITED(i))
		g_exit_status = WEXITSTATUS(i);
	else
		g_exit_status = EXIT_FAILURE;
}
