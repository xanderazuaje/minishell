/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:04:10 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:39:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

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
		var_val = get_var_val(var_name, env);
		free(var_name);
		last = insert(last, local[0], local[1], var_val);
		free(var_val);
		free(temp);
		temp = last;
	}
	return (last);
}
