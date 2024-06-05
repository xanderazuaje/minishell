/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:29 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 05:08:06 by xander           ###   ########.fr       */
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

t_states	get_state(t_states prev, t_states curr);
#endif
