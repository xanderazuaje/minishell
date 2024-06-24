/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:46:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/24 06:19:28 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start_with(const char *str, const char *find)
{
	while (*str && *find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	if (!*find && *str == '=')
		return (1);
	return (0);
}
