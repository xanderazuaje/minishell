/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:03 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 16:55:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"
# include "split_sh/split_sh.h"
# include "expansor/expansor.h"
# include "lexer/lexer.h"
# include "../types.h"
# include <stdlib.h>

t_cmdlist	*parse_str(char *str, char **env);
char **envcopy(char **env);
void freeenv(char ***env);

#endif
