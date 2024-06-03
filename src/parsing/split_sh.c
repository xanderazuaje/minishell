/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:33:20 by xander            #+#    #+#             */
/*   Updated: 2024/06/04 01:03:56 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmdlist *create_cmd(char *word, short flag)
{
	t_cmdlist *node;

	node = (t_cmdlist *) malloc(sizeof (t_cmdlist));
	if (!node)
		return NULL;
	node->next = NULL;
	node->flags = flag;
	node->word = word;
	return (node);
}

void append_cmd(t_cmdlist *list, t_cmdlist *node)
{
	while (list->next)
		list = list->next;
	list->next = node;
}

void free_cmd(t_cmdlist *list)
{
	t_cmdlist *temp;
	if (!list)
		return;
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

size_t len_to_ptr(char *org, const char *dest)
{
	size_t	i;

	i = 0;
	while (org != dest)
	{
		org++;
		i++;
	}
	return i;
}

void add_node(t_cmdlist **list, char *str) {
	t_cmdlist *node;

	node = create_cmd(str, 0);
	if (!node)
	{
		free_cmd(*list);
		perror("error");
		exit(127);
	}
	if (!*list)
		*list = node;
	else
		append_cmd(*list, node);
}

int is_keyword(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == '*');
}

t_cmdlist *split_sh(const char *str)
{
	t_cmdlist *list;
	char	*cw;
	char	quotes;
	char	is_word;

	list = NULL;
	quotes = '\0';
	is_word = 'F';
	while (1)
	{
		if ( quotes == '\0' && (*str == '\'' || *str == '"'))
		{
			quotes = *str;
			cw = (char *) str;
			is_word = 'T';
			str++;
		}
		if ((quotes == '\0' && (isspace(*str) || is_keyword(*str))) || *str == '\0')
		{
			if (is_word == 'T')
			{
				is_word = 'F';
				add_node(&list, ft_substr(cw, 0, len_to_ptr(cw, str)));
			}
			if (*str == '*')
			{
				add_node(&list, ft_strdup("*"));
			}
			else if (*str == '|')
			{
				if (*(str + 1) == '|')
				{
					str++;
					add_node(&list, ft_strdup("||"));
				}
				else
					add_node(&list, ft_strdup("|"));
			}
			else if (*str == '>')
			{
				if (*(str + 1) == '>')
				{
					str++;
					add_node(&list, ft_strdup(">>"));
				}
				else
					add_node(&list, ft_strdup(">"));
			}
			else if (*str == '<')
			{
				if (*(str + 1) == '<')
				{
					str++;
					add_node(&list, ft_strdup("<<"));
				}
				else
					add_node(&list, ft_strdup("<"));
			}
			else if (*str == '&')
			{
				if (*(str + 1) == '&')
				{
					str++;
					add_node(&list, ft_strdup("&&"));
				}
				else
					add_node(&list, ft_strdup("&"));
			}
			if (*str == '\0')
				break;
		}
		else {
			if (is_word == 'F')
			{
				cw = (char *) str;
				is_word = 'T';
			}
		}
		if (*str == quotes)
		{
			is_word = 'F';
			add_node(&list, ft_substr(cw, 0, len_to_ptr(cw, str + 1)));
			quotes = '\0';
		}
		str++;
	}
	return (list);
}

