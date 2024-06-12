/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:01 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 01:01:25 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"
#include "../types.h"

void	set_it_null(char *str, char *save[2])
{
	save[0] = NULL;
	save[1] = NULL;
}

void	get_var_loc(char *str, char *save[2])
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && isalnum(str[i + 1]))
			break ;
		i++;
	}
	if (!str[i])
		set_it_null(str, save);
	else if (isdigit(str[i + 1]))
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 1]);
	}
	else if (isalpha(str[i + 1]))
	{
		save[0] = &(str[i]);
		i++;
		while (isalnum(str[i]))
			i++;
		save[1] = &(str[i]);
	}
}
