/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:29 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:04:07 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 5/22/24.
//

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"
# include "split_sh/split_sh.h"
# include "types.h"
# include <stdlib.h>

# define INIT 0
# define ERRO 1
# define HDOC 2
# define DELM 3
# define REDI 4
# define COMM 5
# define ARGU 6
# define OPER 7
# define FILE 8
# define ENDL 9

typedef enum e_states
{
	initial = INIT,
	error = ERRO,
	here_doc = HDOC,
	delimiter = DELM,
	redirection = REDI,
	command = COMM,
	argument = ARGU,
	operator = OPER,
	file = FILE,
	end = ENDL
}	t_states;

#endif
