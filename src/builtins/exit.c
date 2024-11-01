/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 17:39:46 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void do_exit(char **args, char ***env)
{
    int exit_status = prev_exit_status(0);

    if (args[1] != NULL)
    {
        int status;
        status = ft_atoi(args[1]);
        
        if (status < 0)
			exit_status = 179;
        else if (status > 255)
            exit_status = 244;
        else
            exit_status = status;
    }
    freeenv(env);
    prev_exit_status(exit_status);
    exit(exit_status);
}