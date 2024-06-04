/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:33:20 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:18:27 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_split_sh.h"

size_t	len_to_ptr(char *org, const char *dest)
{
	size_t	i;

	i = 0;
	while (org != dest)
	{
		org++;
		i++;
	}
	return (i);
}

void	end_word_if_can(const char *str, char **cw, char *is_word)
{
	if ((*is_word) == 'F')
	{
		(*cw) = (char *) str;
		(*is_word) = 'T';
	}
}

/*
 * cw: current position for the word
 * str: string:37
 * l: reference to linked l of commands
 * iw: is word
 */
void	clip_and_add(char *cw, const char **str, t_cmdlist **l, char *iw)
{
	if ((*iw) == 'T')
	{
		(*iw) = 'F';
		add_node(l, ft_substr(cw, 0, \
		len_to_ptr(cw, (*str))));
	}
	if (*(*str) == '*')
	{
		add_node(l, ft_strdup("*"));
	}
	else if (is_keyword(*(*str)))
	{
		add_keyword_node((*str), l);
		if (*((*str) + 1) == *(*str))
			(*str)++;
	}
}

int	can_cut(const char *str, char quotes)
{
	return ((quotes == '\0' && (isspace(*str) || is_keyword(*str))) \
		|| *str == '\0');
}

/*
 * cw: current position for the word
 * str: string:37
 * l: reference to linked l of commands
 * iw: is word
 */
t_cmdlist	*split_sh(const char *str)
{
	t_cmdlist	*l;
	char		*cw;
	char		q;
	char		iw;

	l = NULL;
	q = '\0';
	iw = 'F';
	while (1)
	{
		if (q == '\0' && (*str == '\'' || *str == '"'))
			start_quoting(&str, &cw, &q, &iw);
		if (can_cut(str, q))
		{
			clip_and_add(cw, &str, &l, &iw);
			if (*str == '\0')
				break ;
		}
		else
			end_word_if_can(str, &cw, &iw);
		if (*str == q)
			q = end_quoting(ft_substr(cw, 0, len_to_ptr(cw, str + 1)), &l, &iw);
		str++;
	}
	return (l);
}
