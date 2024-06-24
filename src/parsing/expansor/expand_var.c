/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:04:10 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/24 06:16:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

int is_protected(char c)
{
	return (c == '"' || c == '\'' || c == '|' || c == '&' || c == '<'
		|| c == '>');
}

int has_protected(char *str)
{
	while (*str)
	{
		if (is_protected(*str))
			return (1);
		str++;
	}
	return (0);
}

int count_protected(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (is_protected(*str))
			i++;
		str++;
	}
	return (i);
}

char *protect(char *str)
{
	int protected_chars;
	size_t len;
	char *final;
	int i;

	i = 0;
	protected_chars = count_protected(str);
	len = ft_strlen(str);
	final = (char *) safe_malloc(len + protected_chars + 1);
	while (*str)
	{
		if (is_protected(*str))
			final[i++] = '\\';
		final[i++] = *str;
		str++;
	}
	final[i] = '\0';
	return final;
}


char	*expand_var(char *str, char **env)
{
	char	*local[2];
	char	*last;
	char	*var_name;
	char	*var_val;
	char	*temp;

	local[0] = (char *) 1;
	local[1] = (char *) 1;
	last = str;
	temp = NULL;
	while (last)
	{
		get_var_loc(last, local);
		if (!local[0])
			break ;
		var_name = ft_substr(local[0], 0, len_to_ptr(local[0], local[1]));
		temp = var_name;
		var_val = get_var_val(var_name, env);
		free(temp);
		if (var_val && has_protected(var_val))
		{
			temp = var_val;
			var_val = protect(var_val);
			free(temp);
		}
		temp = last;
		last = insert(last, local[0], local[1], var_val);
		free(var_val);
		free(temp);
	}
	return (last);
}
