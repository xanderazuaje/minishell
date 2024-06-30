/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:54:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/30 21:05:13 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../types.h"
#include "_expansor.h"

int	add_expanded_quotes(char **env, t_cmdlist *node, int hdoc)
{
	char	*temp;

	temp = node->word;
	if (ft_strncmp(node->word, "<<", 2) == 0)
		hdoc = 1;
	if (!hdoc)
	{
		node->word = expand_quotes(node->word, env);
		free(temp);
		hdoc = 0;
	}
	return (hdoc);
}

t_cmdlist	*expand(char *input, char **env)
{
	char		*var_expanded;
	t_cmdlist	*splitted;
	t_cmdlist	*node;
	int			hdoc;

	var_expanded = expand_var(input, env);
	if (!var_expanded)
		var_expanded = ft_strdup("");
	splitted = split_sh(var_expanded);
	free(var_expanded);
	tokenizer(splitted);
	node = splitted;
	hdoc = 0;
	while (node)
	{
		hdoc = add_expanded_quotes(env, node, hdoc);
		node = node->next;
	}
	return (splitted);
}
