/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:19:47 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/13 14:20:57 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

int	count_processes(const t_cmdlist *list)
{
	int	i;

	i = 1;
	while (list)
	{
		if (list->flags == pipe_flag)
			i++;
		list = list->next;
	}
	return (i);
}

int	count_args(const t_cmdlist *list)
{
	int	i;

	i = 1;
	while (list && list->flags != pipe_flag)
	{
		if (list->flags == argument || list->flags == command)
			i++;
		list = list->next;
	}
	return (i);
}
