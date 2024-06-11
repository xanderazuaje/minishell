/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:03 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"
# include "split_sh/split_sh.h"
# include "expansor/expansor.h"
# include "types.h"
# include <stdlib.h>

t_states	get_state(t_states prev, t_states curr);
#endif
