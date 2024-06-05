/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:54:44 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:45:27 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define INIT 0
# define ERRO 1
# define HDOC 2
# define DELI 3
# define REDI 4
# define IOFL 5
# define COMM 6
# define ARGU 7
# define PIPE 8
# define LOGA 9
# define LOGO 10
# define ENDL 11

typedef enum e_states
{
	initial = INIT,
	error = ERRO,
	here_doc = HDOC,
	delimiter = DELI,
	redirection = REDI,
	io_file = IOFL,
	command = COMM,
	argument = ARGU,
	pipe_op = PIPE,
	log_and = LOGA,
	log_or = LOGO,
}	t_states;

typedef struct s_cmdlist
{
	char				*word;
	t_states			flags;
	struct s_cmdlist	*next;
}	t_cmdlist;
#endif
