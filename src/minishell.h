/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:19:40 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/08/29 13:59:58 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <string.h>
# include "../lib/libft/libft.h"
# include <readline/readline.h>
# include <signal.h>
# include <readline/history.h>
# include <errno.h>
/* - GLOBALS -*/
# include "globals/globals.h"
/* -------------* PARSING *------------------ */
# include "parsing/parser.h"
# include "types.h"
/* ------------* EXECUTING *----------------- */
# include "executor/executor.h"
/* -------------* TESTING *------------------ */
# include "feature_test/feature_test.h"
/* -------------* BUILTINS *------------------ */
# include "builtins/builtins.h"
/* -------------* SIGNALS *------------------ */
void	init_signals(void);

#endif
