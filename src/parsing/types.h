/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:54:44 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:04:39 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_cmdlist
{
	char				*word;
	short				flags;
	struct s_cmdlist	*next;
}	t_cmdlist;
#endif
