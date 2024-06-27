/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:28:44 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 16:16:18 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmdlist	*parse_str(char *str, char **env)
{
	if (!check_input(str))
	{
		prev_exit_status(2);
		return (NULL);
	}
	return (expand(str, env));
}
