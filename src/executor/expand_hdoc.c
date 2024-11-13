/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_hdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 06:36:59 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/08/17 10:52:27 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

void	set_limits_hdoc(char *str, char *save[2], size_t i)
{
	if (!str[i])
	{
		save[0] = NULL;
		save[1] = NULL;
	}
	else if (ft_isdigit(str[i + 1]) || str[i + 1] == '?')
	{
		save[0] = &(str[i]);
		save[1] = &(str[i + 2]);
	}
	else if (ft_isalpha(str[i + 1]) || str[i + 1] == '_')
	{
		save[0] = &(str[i]);
		i++;
		while (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		save[1] = &(str[i]);
	}
}

void	get_var_loc_hdoc(char *str, char *save[2])
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && is_valid_varname(str[i + 1]))
			break ;
		i++;
	}
	set_limits_hdoc(str, save, i);
}

char	*expand_hdoc(char *str, char **env)
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
		get_var_loc_hdoc(last, local);
		if (!local[0])
			break ;
		var_name = ft_substr(local[0], 0, len_to_ptr(local[0], local[1]));
		temp = var_name;
		var_val = get_var_val(var_name, env);
		free(temp);
		last = insert_var(local, last, var_val);
	}
	return (last);
}
