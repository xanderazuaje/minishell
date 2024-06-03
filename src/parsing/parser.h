/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:29 by xander            #+#    #+#             */
/*   Updated: 2024/06/02 05:59:17 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 5/22/24.
//

#ifndef MINISHELL_PARSER_H
#define MINISHELL_PARSER_H

#include "../minishell.h"
#include <stdlib.h>

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

typedef enum e_states {
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
} t_states;

typedef struct s_cmdlist {
	char				*word;
	short				flags;
	struct s_cmdlist	*next;
} t_cmdlist;

size_t	word_counter(char const *str);
t_cmdlist *split_sh(const char *str);
void free_cmd(t_cmdlist *list);
#endif
