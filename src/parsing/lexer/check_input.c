/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:21:38 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/24 17:05:17 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_input(char *str)
{
	t_states	prev;
	t_states	curr;

	prev = initial;
	while (1)
	{
		if ((*str == '&' || *str == '\\' || *str == ';') && prev != quotes)
			curr = error;
		else if (*str == '<' || *str == '>')
			curr = redirection;
		else if (*str == '"' || *str == '\'')
			if (prev == quotes)
				curr = end_of_quote;
			else
				curr = quotes;
		else if (*str == '|')
			curr = pipes;
		else if (*str == '\0')
			curr = last;
		else
			curr = any_character;
		curr = get_state(prev, curr);
		if (curr == error)
		{
			write(2, "syntax error near unexpected token '", 36);
			write(2, str, 1);
			write(2, "'\n", 2);
			return (0);
		}
		if (curr == last)
			return (1);
		prev = curr;
		str++;
	}
}