/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:21:38 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 12:38:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

void	syntax_error(char c)
{
	write(2, "syntax error near unexpected token ", 36);
	if (c == '\0')
		write(2, "newline", 7);
	else
		write(2, &c, 1);
	write(2, "'\n", 2);
}

void	check_quotes_state(const char *s, const t_states *p, char *pq,
	t_states *c)
{
	if (*p == quotes && *s == *pq)
	{
		*c = end_of_quote;
		*pq = '\0';
	}
	else if (*p == quotes)
	{
		*c = any_character;
	}
	else
	{
		*pq = *s;
		*c = quotes;
	}
}

t_states	check_states(const char *str, const t_states *prev, char *prev_q)
{
	t_states	curr;

	if (*str == '\\' || ((*str == '&' || *str == ';') && *prev != quotes))
		curr = error;
	else if (*str == '<' || *str == '>')
		curr = redirection;
	else if (*str == '"' || *str == '\'')
	{
		check_quotes_state(str, prev, prev_q, &curr);
	}
	else if (*str == '|')
		curr = pipes;
	else if (*str == '\0')
		curr = last;
	else
		curr = any_character;
	return (curr);
}

int	check_input(char *str)
{
	t_states	prev;
	t_states	curr;
	char		prev_q;

	prev = initial;
	prev_q = '\0';
	while (1)
	{
		while (*str == ' ')
			str++;
		curr = check_states(str, &prev, &prev_q);
		curr = get_state(prev, curr);
		if (curr == error)
		{
			if (prev == quotes)
				write(2, "invalid syntax\n", 15);
			else
				syntax_error(*str);
			return (0);
		}
		if (curr == last)
			return (1);
		prev = curr;
		str++;
	}
}
