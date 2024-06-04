/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split_sh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:38:11 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:11:18 by xander           ###   ########.fr       */
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

t_cmdlist	*create_cmd(char *word, short flag);
void		append_cmd(t_cmdlist *list, t_cmdlist *node);
void		add_node(t_cmdlist **list, char *str);
int			is_keyword(char c);
void		add_keyword_node(const char *str, t_cmdlist **list);
void		start_quoting(const char **str, char **cw, char *q, char *iw);
char		end_quoting(char *str, t_cmdlist **list, char *is_word);

#endif
