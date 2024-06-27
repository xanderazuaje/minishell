/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:04:10 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/27 16:24:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*protect(char *str)
{
	int		protected_chars;
	size_t	len;
	char	*final;
	int		i;

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
	return (final);
}

char	*protect_char(char *var_val)
{
	char	*temp;

	temp = var_val;
	var_val = protect(var_val);
	free(temp);
	return (var_val);
}

char	*insert_var(char *const *local, char *last, char *var_val)
{
	char	*temp;

	temp = last;
	last = insert(last, local[0], local[1], var_val);
	free(var_val);
	free(temp);
	return (last);
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
			var_val = protect_char(var_val);
		last = insert_var(local, last, var_val);
	}
	return (last);
}
