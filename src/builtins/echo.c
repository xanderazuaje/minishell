/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/02 11:43:48 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	has_flag(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '-' || str[1] != 'n')
		return (1);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	do_echo(char **args)
{
	int	linebr;
	int	i;

	if (!args || !args[1])
		return (printf("\n"), 0);
	linebr = has_flag(args[1]);
	i = 1;
	while (args[i] != NULL)
	{
		if (args[i][0] == '-' && args[i][1] == 'n' && linebr == 0)
			i++;
		else
			break ;
	}
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		if (args[i + 1] && args[i + 1][0] != '\0')
			printf(" ");
		i++;
	}
	if (linebr == 1)
		printf("\n");
	return (0);
}
