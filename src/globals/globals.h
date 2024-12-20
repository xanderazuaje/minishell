/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:46:03 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 17:53:35 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

extern int		g_exit_status;
void			set_exit_status(int i);

#endif
