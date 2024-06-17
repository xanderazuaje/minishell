/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:05:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 03:55:39 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

void	quote_err(const char *quote)
{
	write(2, "error: unclosed quote: ", 22);
	write(2, quote, 1);
	write(2, " \n", 2);
	exit(1);
}

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
	if (!str[*i] && *quote != '\0')
		quote_err(quote);
	if (*i > 2)
	{
		return (ft_substr(str, 1, *i - 2));
	}
	return (NULL);
}
