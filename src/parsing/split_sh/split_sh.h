/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:35:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/01 22:46:04 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_SH_H
# define SPLIT_SH_H

# include "../../types.h"

t_cmdlist	*split_sh(const char *str);
void		free_cmd(t_cmdlist *list);
int			is_keyword(char c);
#endif
