/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:49:53 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/02 19:27:59 by mhiguera         ###   ########.fr       */
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
	printf("*env: %s\n", *env);
	while (*env && !start_with(*env, str + 1))
		env++;
	if (!*env)
		return (NULL);
	printf("hola llego aquí acaso?\n");
	var = *env;
	while (*var != '=')
	{
		var++;
	}
	var++;
	return (ft_strdup(var));
}
