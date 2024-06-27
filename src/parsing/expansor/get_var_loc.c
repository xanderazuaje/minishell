/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:01 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 17:38:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

int	isquote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_valid_varname(char c)
{
	return (isalnum(c) || c == '_' || isquote(c) || c == '?');
}

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

void	get_var_loc(char *str, char *save[2])
{
	size_t	i;
	char	quote;

	i = 0;
	quote = '\0';
	while (str[i])
	{
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
		else if (quote && (str[i] == '"' || str[i] == '\''))
			quote = '\0';
		i++;
	}
	set_limits(str, save, i, quote);
}
