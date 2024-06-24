/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:23:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/24 17:16:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_states	get_state(t_states prev, t_states curr)
{
	static t_states	states[LAST + 1][LAST + 1]  = {
		{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, ERRO }, //	INIT 0
		{ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO }, //	ERRO 1
		{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, REDI, LAST }, //	ANYC 2
		{ERRO, ERRO, QUOT, ERRO, ENDQ, QUOT, QUOT, LAST }, //	QUOT 3
		{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, REDI, LAST }, //	ENDQ 4
		{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, ERRO }, //	PIPE 5
		{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, ERRO }, //	REDI 6
		{LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST }, //	LAST 8
	};
	return (states[prev][curr]);
}
