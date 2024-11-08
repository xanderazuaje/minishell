/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:01 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 13:03:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

short	skip_redir(const char *str, size_t *p)
{
	size_t	i;

	i = *p;
	if (str[i] == '<' || str[i] == '>')
	{
		i += 2;
		while (isspace(str[i]))
			i++;
		while (str[i] && !is_keyword(str[i]) && !isspace(str[i]))
			i++;
	}
	*p = i;
	if (!str[i])
		return (-1);
	return (0);
}

int	isquote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_valid_varname(char c)
{
	return (isalnum(c) || c == '_' || isquote(c) || c == '?');
}

void	get_var_loc(char *str, char *save[2])
{
	size_t	i;
	char	quote;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (skip_redir(str, &i) == -1)
			break ;
		if (!quote || quote == '"')
		{
			if (str[i] == '$' && is_valid_varname(str[i + 1]))
			{
				if (isquote(str[i + 1]))
					quote = str[i + 1];
				break ;
			}
		}
		if (!quote && (str[i] == '"' || str[i] == '\''))
			quote = str[i];
		else if (quote && (str[i] == '"' || str[i] == '\'') && str[i] == quote)
			quote = '\0';
		i++;
	}
	set_limits(str, save, i, quote);
}
