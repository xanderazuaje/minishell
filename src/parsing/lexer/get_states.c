/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:23:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 17:41:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_states	get_state(t_states prev, t_states curr)
{
	static t_states	states[LAST + 1][LAST + 1] = {
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, LAST},
	{ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, REDI, LAST},
	{ERRO, ERRO, QUOT, ERRO, ENDQ, QUOT, QUOT, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, PIPE, REDI, LAST},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, ERRO},
	{ERRO, ERRO, ANYC, QUOT, ERRO, ERRO, REDI, ERRO},
	{LAST, LAST, LAST, LAST, LAST, LAST, LAST, LAST},
	};

	return (states[prev][curr]);
}
