/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:54:44 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 21:29:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define INIT 0
# define ERRO 1
# define ANYC 2
# define QUOT 3
# define ENDQ 4
# define PIPE 5
# define IRED 6
# define IRDD 7
# define ORED 8
# define ORDD 9
# define LAST 10

typedef enum e_states
{
	initial = INIT,
	error = ERRO,
	any_character = ANYC,
	quotes = QUOT,
	end_of_quote = ENDQ,
	pipes = PIPE,
	redirection_in = IRED,
	redirection_in_double = IRDD,
	redirection_out =ORED,
	redirection_out_double = ORDD,
	last = LAST
}	t_states;

typedef enum e_flags
{
	init,
	command,
	argument,
	pipe_flag,
	here_document,
	here_document_limit,
	infile,
	outfile,
	append_outfile,
	file_name,
}	t_flags;

typedef struct s_cmdlist
{
	char				*word;
	t_flags				flags;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_cmd
{
	char	**arg_list;
	char	*cmd;
}	t_cmd;

#endif
