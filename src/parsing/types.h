/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:54:44 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/19 07:29:19 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>

# define INIT 0
# define ERRO 1
# define ANYC 2
# define QUOT 3
# define ENDQ 4
# define PIPE 5
# define REDI 6
# define VARS 7
# define LAST 8

typedef enum e_states
{
	initial = INIT,
	error = ERRO,
	any_character = ANYC,
	quotes = QUOT,
	end_of_quote = ENDQ,
	pipes = PIPE,
	redirection = REDI,
	variables = VARS,
	last = LAST

}	t_states;

typedef struct s_cmdlist
{
	char				*word;
	t_states			flags;
	struct s_cmdlist	*next;
}	t_cmdlist;
#endif
