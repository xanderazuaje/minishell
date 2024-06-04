/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:42:31 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:07:39 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_split_sh.h"

int	is_keyword(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == '*');
}

void	add_keyword_node(const char *str, t_cmdlist **list)
{
	if (*(str + 1) == *str)
		add_node(list, ft_substr(str, 0, 2));
	else
		add_node(list, ft_substr(str, 0, 1));
}

/*
 * str: string
 * cw: current position for the word
 * q: quoting status
 * iw: is word
 */
void	start_quoting(const char **str, char **cw, char *q, char *iw)
{
	(*q) = *(*str);
	(*cw) = (char *)(*str);
	(*iw) = 'T';
	(*str)++;
}

char	end_quoting(char *str, t_cmdlist **list, char *is_word)
{
	(*is_word) = 'F';
	add_node(list, str);
	return ('\0');
}
