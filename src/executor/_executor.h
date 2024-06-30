/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:48:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/28 02:25:22 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXECUTOR_H
#define _EXECUTOR_H

# define WR_PIPE 1
# define RD_PIPE 0
# include "../types.h"
# include <stdarg.h>
#include "../minishell.h"

void executor(t_cmdlist *list);

#endif
