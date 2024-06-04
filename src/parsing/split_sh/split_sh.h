/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt_sh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:35:35 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:10:55 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_SH_H
# define SPLIT_SH_H

# include "../types.h"

t_cmdlist	*split_sh(const char *str);
void		free_cmd(t_cmdlist *list);
#endif
