/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:06:12 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/16 02:50:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*get_prefix(const char *str, char *quote, size_t *i)
{
	*i = 0;
	while (str[*i] != *quote)
	{
		if (str[*i] == '\\')
			(*i)++;
		else if (!*quote && (str[*i] == '\'' || str[*i] == '"'))
		{
			*quote = str[*i];
			continue ;
		}
		(*i)++;
	}
	if (*i > 0)
		return (ft_substr(str, 0, *i));
	else
		return (NULL);
}
