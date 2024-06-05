/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split_sh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:38:11 by xander            #+#    #+#             */
/*   Updated: 2024/06/05 04:37:58 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 6/4/24.
//

#ifndef _SPLIT_SH_H
# define _SPLIT_SH_H

# include <stdlib.h>
# include <ctype.h>
# include "../types.h"
# include "../../../lib/libft/libft.h"

t_cmdlist	*create_cmd(char *word);
void		append_cmd(t_cmdlist *list, t_cmdlist *node);
void		add_node(t_cmdlist **list, char *str);
int			is_keyword(char c);
void		add_keyword_node(const char *str, t_cmdlist **list);

#endif
