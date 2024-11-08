/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:25:43 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 12:40:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:48:27 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/08 12:11:30 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	export_error(char *str)
{
	write(2, "export: ", 8);
	ft_putstr_fd(str, 2);
	write(2, " not a valid identifier\n", 24);
}

int	builtin_export(char *str, char ***env)
{
	int	i;

	i = 0;
	if (*str == '=')
	{
		export_error(str);
		return (1);
	}
	while (str[i] && str[i] != '=')
	{
		if ((!ft_isalnum(str[i]) && str[i] != '_')
			|| (!ft_isalpha(str[0]) && str[0] != '_'))
		{
			export_error(str);
			return (1);
		}
		i++;
	}
	if (str[i] != '=')
		return (0);
	insert_variable(str, env);
	return (0);
}

int	do_export(char **args, char ***env)
{
	int	num;

	num = 1;
	while (args[num] != NULL && num > 0)
	{
		builtin_export(args[num], env);
		num++;
	}
	return (0);
}
