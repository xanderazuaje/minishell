/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:19:40 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 23:46:02 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include <readline/readline.h>
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
#endif
