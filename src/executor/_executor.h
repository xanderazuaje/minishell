/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:48:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/02 01:45:29 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXECUTOR_H
#define _EXECUTOR_H

# define WR_PIPE 1
# define RD_PIPE 0
# include "../types.h"
# include <stdarg.h>
# include <fcntl.h>
# include "../minishell.h"

void executor(t_cmdlist *list);

#endif
