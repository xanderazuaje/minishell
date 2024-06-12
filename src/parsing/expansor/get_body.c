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

char	*body_concat_expand(const char *str, size_t *i, char **env, char q)
{
	char	*str2;
	char	*temp;

	str2 = ft_substr(str, 1, *i - 2);
	temp = str2;
	if (q == '"')
		str2 = expand_var(str2, env);
	if (str2 != temp)
		free(temp);
	return (str2);
}

char	*get_body(const char *str, char *quote, size_t *i, char **env)
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
		if ((str[(*i)] == '\'' || str[(*i)] == '"'))
			*quote = '\0';
		(*i)++;
	}
	if (!str[*i] && *quote != '\0')
		quote_err(quote);
	if (*i > 2)
	{
		return (body_concat_expand(str, i, env, quote_char));
	}
	return (NULL);
}
