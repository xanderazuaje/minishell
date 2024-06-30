/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:05:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/30 20:59:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*get_body(const char *str, char *quote, size_t *i)
{
	char	quote_char;

	quote_char = *quote;
	*i = 0;
	if (!*str)
		return (NULL);
	if (str[*i] == *quote)
		(*i)++;
	while (str[*i] && *quote)
	{
		if (str[(*i)] == '\\')
			(*i)++;
		else if (str[(*i)] == quote_char)
			*quote = '\0';
		(*i)++;
	}
	if (*i > 2)
	{
		return (ft_substr(str, 1, *i - 2));
	}
	return (NULL);
}
