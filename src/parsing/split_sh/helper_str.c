/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:42:31 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_split_sh.h"

int	is_keyword(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&');
}

void	add_keyword_node(const char *str, t_cmdlist **list)
{
	if (*(str + 1) == *str)
		add_node(list, ft_substr(str, 0, 2));
	else
		add_node(list, ft_substr(str, 0, 1));
}
