/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:38:11 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 04:21:51 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"
#include "_split_sh.h"

t_cmdlist	*create_cmd(char *word, short flag)
{
	t_cmdlist	*node;

	node = (t_cmdlist *) malloc(sizeof (t_cmdlist));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->flags = flag;
	node->word = word;
	return (node);
}

void	append_cmd(t_cmdlist *list, t_cmdlist *node)
{
	while (list->next)
		list = list->next;
	list->next = node;
}

void	free_cmd(t_cmdlist *list)
{
	t_cmdlist	*temp;

	if (!list)
		return ;
	while (list->next)
	{
		temp = list->next;
		free(list->word);
		free(list);
		list = temp;
	}
	free(list->word);
	free(list);
}

void	add_node(t_cmdlist **list, char *str)
{
	t_cmdlist	*node;

	node = create_cmd(str, 0);
	if (!node)
	{
		free_cmd(*list);
		perror("error");
		exit(ENOMEM);
	}
	if (!*list)
		*list = node;
	else
		append_cmd(*list, node);
}
