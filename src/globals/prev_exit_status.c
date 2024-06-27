/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:45:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 17:57:03 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int	prev_exit_status(int i)
{
	static int	pid;
	int			temp;

	temp = pid;
	pid = i;
	return (temp);
}
