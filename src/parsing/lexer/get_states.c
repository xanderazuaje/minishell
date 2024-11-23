/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:23:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/23 17:21:49 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>

#include "lexer.h"

/*










*/
t_states	get_state(t_states prev, t_states curr)
{
	static t_states	states[LAST + 1][LAST + 1] = {
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, IRED, ERRO, ORED, ORDD, LAST},
	{ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, IRED, ERRO, ORED, ERRO, LAST},
	{ERRO, ERRO, QUOT, ERRO, ENDQ, QUOT, QUOT, ERRO, QUOT, ERRO, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, IRED, ERRO, ORED, ERRO, LAST},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, IRED, ERRO, ORED, ERRO, LAST},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, ERRO, IRDD, ERRO, ERRO, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, LAST},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, ERRO, ERRO, ERRO, ORDD, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO},
	{LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST},
	};

	return (states[prev][curr]);
}
