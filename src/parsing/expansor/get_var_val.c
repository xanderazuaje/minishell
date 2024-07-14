/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:49:53 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/09 18:03:51 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

char	*get_var_val(const char *str, char **env, int exit_status)
{
	char	*var;

	if (!str)
		return (NULL);
	if (*(str + 1) == '?')
		return (ft_itoa(exit_status));
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
