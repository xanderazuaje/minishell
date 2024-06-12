/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:49:53 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:40:25 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*get_var_val(const char *str, char **env)
{
	char	*var;

	if (!str)
		return (NULL);
	var = NULL;
	while (*env && !start_with(*env, str + 1))
		env++;
	if (!*env)
		return (NULL);
	var = *env;
	while (*var != '=')
	{
		var++;
	}
	var++;
	return (ft_strdup(var));
}
