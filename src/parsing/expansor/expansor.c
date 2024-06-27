/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:54:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 20:59:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "_expansor.h"

t_cmdlist	*expand(char *input, char **env)
{
	char		*var_expanded;
	t_cmdlist	*splitted;
	char		*temp;
	t_cmdlist	*node;

	var_expanded = expand_var(input, env);
	if (!var_expanded)
		var_expanded = ft_strdup("");
	splitted = split_sh(var_expanded);
	free(var_expanded);
	tokenizer(splitted);
	node = splitted;
	while (node)
	{
		temp = node->word;
		node->word = expand_str(node->word, env);
		free(temp);
		node = node->next;
	}
	return (splitted);
}
