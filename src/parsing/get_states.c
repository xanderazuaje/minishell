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
	static t_states	states[ENDL][ENDL]  = {
			{ERRO, ERRO, HDOC, ERRO, REDI,ERRO, COMM, ERRO, ERRO, ERRO, ERRO}, // INIT 0
			{ERRO, ERRO, ERRO, ERRO, ERRO,ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // ERRO 1
			{ERRO, ERRO, ERRO, DELI, ERRO,ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // HDOC 2
			{ERRO, ERRO, HDOC, ERRO, REDI,ERRO, ERRO, ARGU, PIPE, LOGA, LOGO}, // DELI 3
			{ERRO, ERRO, ERRO, ERRO, ERRO,IOFL, ERRO, ERRO, ERRO, ERRO, ERRO}, // REDI 4
			{ERRO, ERRO, HDOC, ERRO, ERRO,ERRO, ERRO, ARGU, PIPE, LOGA, LOGO}, // IOFL 5
			{ERRO, ERRO, HDOC, ERRO, ERRO,ERRO, ERRO, ARGU, PIPE, LOGA, LOGO}, // COMM 6
			{ERRO, ERRO, HDOC, ERRO, ERRO,ERRO, ERRO, ARGU, PIPE, LOGA, LOGO}, // ARGU 7
			{INIT, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // PIPE 8
			{INIT, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // LOGA 9
			{INIT, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // LOGO 10
	};

	return (states[prev][curr]);
}
