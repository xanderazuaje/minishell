/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:01 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/17 08:12:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

void	set_it_null(char *save[2])
{
	save[0] = NULL;
	save[1] = NULL;
}

void	get_var_loc(char *str, char *save[2])
{
	size_t	i;
	char quote;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (!quote || quote == '"')
			if (str[i] == '$' && (isalnum(str[i + 1]) || str[i + 1] == '_'))
				break ;
		if (!quote && (str[i] == '"' || str[i] == '\''))
			quote = str[i];
		else if (quote && (str[i] == '"' || str[i] == '\''))
			quote = '\0';
		i++;
	}
	if (!str[i])
		set_it_null(save);
	else if (isdigit(str[i + 1]))
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 1]);
	}
	else if (isalpha(str[i + 1]) || str[i + 1] == '_')
	{
		save[0] = &(str[i]);
		i++;
		while (isalnum(str[i]) || str[i] == '_')
			i++;
		save[1] = &(str[i]);
	}
}
