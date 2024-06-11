/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:54:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/10 18:53:18 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../types.h"
#include "expansor.h"

// TODO: Order this mess

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

char *get_var_val(const char *str, char **env)
{
	char *var;
	if (!str)
		return NULL;
	var = NULL;
	while (*env && !start_with(*env, str + 1))
		env++;
	if (!*env)
		return NULL;
	var = *env;
	while(*var != '=')
	{
		var++;
	}
	var++;
	return ft_strdup(var);
}
#include <ctype.h>

char *insert(char *str, char *start, char *end, char *to_insert)
{
	char *prefix;
	char *suffix;
	char *final;

	prefix = NULL;
	suffix = NULL;
	if (start == end)
		return	(NULL);
	if (start != str)
		prefix = ft_substr(str, 0, len_to_ptr(str, start));
	if (*end)
		suffix = ft_substr(end, 0, ft_strlen(end));
	if (!to_insert && !prefix && !suffix)
		return NULL;
	if (!to_insert)
	{
		if (prefix && suffix)
			final = ft_strjoin(prefix, suffix);
		else if (!prefix)
			final = suffix;
		else
			final = prefix;
	}
	else if (!prefix)
		final = ft_strjoin(to_insert, suffix);
	else if (!suffix)
		final = ft_strjoin(prefix, to_insert);
	else {
		final = prefix;
		prefix = ft_strjoin(prefix, to_insert);
		free(final);
		final = ft_strjoin(prefix, suffix);
	}
	if (suffix != final)
		free(suffix);
	if (prefix != final)
		free(prefix);
	return  (final);
}

#include <stdio.h>

void get_var_loc(char *str, char *save[2]) {
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && isalnum(str[i + 1]))
			break;
		i++;
	}
	if (!str[i]) {
		save[0] = NULL;
		save[1] = NULL;
		return;
	}
	if (isdigit(str[i + 1])) {
		save[0] = &(str[i]);
		save[1] = &(str[i + 1]);
		return;
	}
	else if (isalpha(str[i + 1]))
	{
		save[0] = &(str[i]);
		i++;
		while (isalnum(str[i]))
			i++;
		save[1] = &(str[i]);
		return;
	}
}

char *expand_var(char *str, char **env)
{
	char *local[2];
	char *last;
	char *var_name;
	char *var_val;
	char *temp;

	local[0] = (char *) 1;
	local[1] = (char *) 1;
	last = str;
	temp = NULL;
	while (last)
	{
		get_var_loc(last, local);
		if (!local[0])
			break;
		printf("1: start: %s, end: %s\n", local[0], local[1]);
		var_name = ft_substr(local[0], 0, len_to_ptr(local[0], local[1]));
		printf("2: varname:%s\n", var_name);
		var_val = get_var_val(var_name, env);
		printf("3: var_val: %s\n", var_val);
		free(var_name);
		last = insert(last, local[0], local[1], var_val);
		printf("5: last: %s\n", last);
		free(var_val);
		free(temp);
		temp = last;
	}

	return (last);
}



char *get_body(const char *str, char *quote, size_t *i, char **env)
{
	char *str2;
	char *temp;
	char quote_char;

	quote_char = *quote;
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
	if (!str[*i] && *quote != '\0')
	{
		write(2, "error: unclosed quote\n", 22);
		exit(1);
	}
	if(*i > 2)
	{
		str2 = ft_substr(str, 1, *i - 2);
		temp = str2;
		if (quote_char == '"')
			str2 = expand_var(str2, env);
		if (str2 != temp)
			free(temp);
		return str2;
	}
	return NULL;
}

char *get_prefix(const char *str, char *quote, size_t *i, char **env)
{
	char *str2;
	char *temp;

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
	{

		str2 = ft_substr(str, 0, *i);
		temp = str2;
		str2 = expand_var(str2, env);
		if (str2 != temp)
			free(temp);
		return str2;
	}
	else
		return  NULL;

}

char *expand_str(char *str, char **env)
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
	prefix = get_prefix(str, &quote, &i, env);
	str = str + i;
	body = get_body(str, &quote, &i, env);
	str = str + i;
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
	} else if (body)
		prefix = body;
	suffix = expand_str(str, env);
	if (suffix)
	{
		temp = prefix;
		if (prefix)
		{
			prefix = ft_strjoin(prefix, suffix);
			free(suffix);
		}
		else
			prefix = suffix;
		free(temp);
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
		list->word = expand_str(list->word, env);
		free(temp);
		list = list->next;
	}
}