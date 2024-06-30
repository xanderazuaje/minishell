/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:21:38 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/30 20:43:55 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	syntax_error(char c)
{
	write(2, "syntax error near unexpected token '", 36);
	if (c == '\0')
		write(2, "newline", 7);
	else
		write(2, &c, 1);
	write(2, "'\n", 2);
}

t_states	check_states(const char *str, const t_states *prev)
{
	t_states	curr;

	if ((*str == '&' || *str == '\\' || *str == ';') && (*prev) != quotes)
		curr = error;
	else if (*str == '<' || *str == '>')
		curr = redirection;
	else if (*str == '"' || *str == '\'')
	{
		if ((*prev) == quotes)
			curr = end_of_quote;
		else
			curr = quotes;
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

	prev = initial;
	while (1)
	{
		while (*str == ' ')
			str++;
		curr = check_states(str, &prev);
		curr = get_state(prev, curr);
		if (curr == error)
		{
			if (prev == quotes)
				write(2, "syntax error: unclosed quote\n", 30);
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
