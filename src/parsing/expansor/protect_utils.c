/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 16:26:30 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

int	is_protected(char c)
{
	return (c == '"' || c == '\'' || c == '|' || c == '&' || c == '<'
		|| c == '>');
}

int	has_protected(char *str)
{
	while (*str)
	{
		if (is_protected(*str))
			return (1);
		str++;
	}
	return (0);
}

int	count_protected(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (is_protected(*str))
			i++;
		str++;
	}
	return (i);
}
