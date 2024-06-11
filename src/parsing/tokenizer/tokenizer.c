/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:58:57 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:38 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	assign_states(t_cmdlist *cmdlist, t_states state,
					t_states *prev, t_states *curr) {
	(*curr) = state;
	cmdlist->flags = get_state((*prev), (*curr));
	(*prev) = (*curr);
}

void	tokenizer(t_cmdlist *cmdlist)
{
	t_states	prev;
	t_states	curr;

	prev = initial;
	curr = initial;
	while (cmdlist)
	{
		if (ft_strncmp(cmdlist->word, "|", 2))
			assign_states(cmdlist, pipe_op, &prev, &curr);
		else if (ft_strncmp(cmdlist->word, "||", 3))
			assign_states(cmdlist, log_or, &prev, &curr);
		else if (ft_strncmp(cmdlist->word, "&&", 3))
			assign_states(cmdlist, log_and, &prev, &curr);
		// TODO: Add the rest and add the wisdcard to states
		cmdlist = cmdlist->next;
	}
}
