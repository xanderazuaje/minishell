/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:23:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:41 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_states	get_state(t_states prev, t_states curr)
{
	static t_states	states[LAST][LAST]  = {
		{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, }//		INIT 0
		//		ERRO 1
		//		ANYC 2
		//		QUOT 3
		//		ENDQ 4
		//		PIPE 5
		//		REDI 6
		//		VARS 7
		//		LAST 8
	};
	return (states[prev][curr]);
}
