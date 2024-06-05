/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:42:31 by xander            #+#    #+#             */
/*   Updated: 2024/06/05 03:07:05 by xander           ###   ########.fr       */
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
