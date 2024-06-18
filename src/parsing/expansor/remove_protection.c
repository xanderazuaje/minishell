/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_protection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:37:49 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/17 08:38:39 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_expansor.h"

int count_protections(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '\\')
			i++;
		str++;
	}
	return (i);
}

char	*remove_escapes(char *str){
	int prot;
	size_t i;
	size_t len;
	char *final;

	i = 0;
	prot = count_protections(str);
	len = ft_strlen(str);
	final = (char *) safe_malloc(len - prot + 1);
	while (*str)
	{
		if (*str == '\\')
			str++;
		final[i++] = *str;
		str++;
	}
	final[i] = '\0';
	return final;
}
