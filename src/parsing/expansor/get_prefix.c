/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:06:12 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 01:06:23 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*pf_concat_expand(const char *str, size_t *i, char **env)
{
	char	*str2;
	char	*temp;

	str2 = ft_substr(str, 0, *i);
	temp = str2;
	str2 = expand_var(str2, env);
	if (str2 != temp)
		free(temp);
	return (str2);
}

char	*get_prefix(const char *str, char *quote, size_t *i, char **env)
{
	*i = 0;
	while (str[*i] != *quote)
	{
		if (!*quote && (str[*i] == '\'' || str[*i] == '"'))
		{
			*quote = str[*i];
			continue ;
		}
		(*i)++;
	}
	if (*i > 0)
		return (pf_concat_expand(str, i, env));
	else
		return (NULL);
}
