/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:57:10 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 17:52:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_split_sh.h"

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
	if (is_keyword(*(*str)))
	{
		add_node(l, ft_substr(*str, 0, 1));
		if (*((*str) + 1) == *(*str))
			(*str)++;
	}
}

int	can_cut(const char *str, char quotes)
{
	return ((quotes == '\0' && (is_keyword(*str) || isspace(*str))) \
		|| *str == '\0');
}

char	check_quotes(const char *str, char q, int is_escaped)
{
	if (is_escaped == 2)
		is_escaped = 0;
	if (*str == '\\' || is_escaped)
		is_escaped++;
	if (q == '\0' && (*str == '\'' || *str == '"') && is_escaped == 0)
		q = *str;
	else if (*str == q)
		q = '\0';
	return (q);
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
	int			is_escaped;

	l = NULL;
	q = '\0';
	iw = 'F';
	is_escaped = 0;
	while (1)
	{
		q = check_quotes(str, q, is_escaped);
		if (can_cut(str, q))
		{
			clip_and_add(cw, &str, &l, &iw);
			if (*str == '\0')
				break ;
		}
		else
			end_word_if_can(str, &cw, &iw);
		str++;
	}
	return (l);
}
