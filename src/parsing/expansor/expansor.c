/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:54:46 by xander            #+#    #+#             */
/*   Updated: 2024/06/09 03:01:12 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "expansor.h"

int	start_with(const char *str, const char *find)
{
	while (*str && *find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	return (1);
}

const char *get_var_val(const char *str)
{
	if (!str)
		return NULL;
	while(*str != '=')
	{
		str++;
	}
	str++;
	return str;
}

#include <stdio.h>


char *get_body(const char *str, char *quote, size_t *i)
{
	*i = 0;
	if (!*str)
		return NULL;
	if (str[*i] == *quote)
	{
		(*i)++;
	}
	while(str[*i] && *quote)
	{
		if ((str[(*i)] == '\'' || str[(*i)] == '"'))
			*quote = '\0';
		(*i)++;
	}
	if(*i > 2)
	{
		return ft_substr(str, 1, *i - 2);
	}
	return NULL;
}

char *get_prefix(const char *str, char *quote, size_t *i)
{
	*i = 0;
	while (str[*i] != *quote)
	{
		if (!*quote && (str[*i] == '\'' || str[*i] == '"'))
		{
			*quote = str[*i];
			continue;
		}
		(*i)++;
	}
	if (*i > 0)
		return ft_substr(str, 0, *i);
	else
		return  NULL;

}

char *expand_str(char *str)
{
	char quote;
	char *temp;
	size_t i;
	char *prefix;
	char *body;
	char *suffix;

	if (!*str)
		return NULL;
	quote = '\0';
	prefix = get_prefix(str, &quote, &i);
	printf("1 %s\n", str);
	str = str + i;
	printf("2 %s\n", str);
	body = get_body(str, &quote, &i);
	str = str + i;
	printf("3 %s\n", str);
	if (prefix && body)
	{
		temp = prefix;
		prefix = ft_strjoin(prefix, body);
		if (!prefix)
		{
			perror("error");
			exit(1);
		}
		free(temp);
		free(body);
	}
	suffix = expand_str(str);
	printf("4 %s\n", str);
	if (suffix)
	{
		temp = prefix;
		prefix = ft_strjoin(prefix, suffix);
		free(temp);
		free(suffix);
	}
	return prefix;
}


void expand(t_cmdlist *list, char **env)
{
	(void ) env;
	char *temp;
	while (list)
	{
		temp = list->word;
		list->word = expand_str(list->word);
		free(temp);
		list = list->next;
	}
}