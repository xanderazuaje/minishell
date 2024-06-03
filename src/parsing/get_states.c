/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:23:08 by xander            #+#    #+#             */
/*   Updated: 2024/05/24 05:10:56 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_states get_state(size_t i, size_t j){
	static t_states states[ENDL + 1][ENDL + 1]  = {
		{ERRO, ERRO, HDOC, ERRO, COMM, REDI, ERRO, ERRO, ERRO, ENDL}, // INIT 0
		{ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO}, // ERRO 1
		{ERRO, ERRO, ERRO, DELM, ERRO, ERRO, ERRO, ERRO, ERRO, ERRO }, // HDOC 2
		{ERRO, ERRO, ERRO, ERRO, ERRO, REDI, ARGU, OPER, }// DELM 3
		// COMM 4
		// REDI 5
		// ARGU 6
		// OPER 7
		// FILE 8
		// ENDL 9
	}
}
