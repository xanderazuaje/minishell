/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:57:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:38:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*insert(char *str, char *start, char *end, char *to_insert)
{
	char	*prefix;
	char	*suffix;
	char	*final;

	prefix = NULL;
	suffix = NULL;
	if (start == end)
		return (NULL);
	if (start != str)
		prefix = ft_substr(str, 0, len_to_ptr(str, start));
	if (*end)
		suffix = ft_substr(end, 0, ft_strlen(end));
	final = varg_strjoin(3, prefix, to_insert, suffix);
	free(suffix);
	free(prefix);
	return (final);
}
