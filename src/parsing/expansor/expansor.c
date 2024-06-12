/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:54:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:41:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "_expansor.h"

void	expand(t_cmdlist *list, char **env)
{
	char	*temp;

	while (list)
	{
		temp = list->word;
		list->word = expand_str(list->word, env);
		free(temp);
		list = list->next;
	}
}
