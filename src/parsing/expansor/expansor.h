/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:53:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/13 19:38:11 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_H
# define EXPANSOR_H

# include "../../types.h"

t_cmdlist	*expand(char *str, char **env);
char		*insert_var(char *const *local, char *last, char *var_val);
char		*get_var_val(const char *str, char **env);
int			is_valid_varname(char c);
char		*expand_quotes(char *str);
#endif
