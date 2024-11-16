/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:19:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/16 20:19:59 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

char	*get_first_command(t_cmdlist *list)
{
	while (list)
	{
		if (list->flags == command)
			return (list->word);
		list = list->next;
	}
	return (NULL);
}
