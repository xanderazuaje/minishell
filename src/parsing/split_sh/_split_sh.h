/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split_sh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:38:11 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/17 08:24:28 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPLIT_SH_H
# define _SPLIT_SH_H

# include <stdlib.h>
# include <ctype.h>
# include "../types.h"
# include "../expansor/expansor.h"
# include "../../../lib/libft/libft.h"

t_cmdlist	*create_cmd(char *word);
void		append_cmd(t_cmdlist *list, t_cmdlist *node);
void		add_node(t_cmdlist **list, char *str);
char		*remove_escapes(char *str);
int			is_keyword(char c);

#endif
