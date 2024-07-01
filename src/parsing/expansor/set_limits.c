/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:19:05 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/02 01:19:37 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

void	limit_quote(char *str, char *save[2], size_t i, char quote)
{
	if (str[i + 2] == quote && str[i + 3] == quote)
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 3]);
	}
	else
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 1]);
	}
}

void	set_limits(char *str, char *save[2], size_t i, char quote)
{
	if (!str[i])
	{
		save[0] = NULL;
		save[1] = NULL;
	}
	else if (isdigit(str[i + 1]) || str[i + 1] == '?')
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 2]);
	}
	else if (isalpha(str[i + 1]) || str[i + 1] == '_')
	{
		save[0] = &(str[i]);
		i++;
		while (isalnum(str[i]) || str[i] == '_')
			i++;
		save[1] = &(str[i]);
	}
	else if (quote)
		limit_quote(str, save, i, quote);
}
