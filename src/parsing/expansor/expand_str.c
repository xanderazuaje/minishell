/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:07:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:31:36 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*expand_str(char *str, char **env)
{
	char		quote;
	char		*final;
	char		*temp;
	size_t		i;
	t_concat	concat;

	if (!*str)
		return (NULL);
	temp = NULL;
	quote = '\0';
	concat.prefix = get_prefix(str, &quote, &i);
	str = str + i;
	concat.body = get_body(str, &quote, &i);
	str = str + i;
	concat.suffix = expand_str(str, env);
	final = varg_strjoin(3, concat.prefix, concat.body, concat.suffix);
	if (final && ft_strchr(final, '\\'))
	{
		temp = final;
		final = remove_escapes(final);
		free(temp);
	}
	free(concat.prefix);
	free(concat.body);
	free(concat.suffix);
	return (final);
}
