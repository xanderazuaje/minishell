/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:55 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/25 00:56:21 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXPANSOR_H
# define _EXPANSOR_H

# include "../../../lib/libft/libft.h"
# include "../split_sh/split_sh.h"
# include "../types.h"
# include "../../globals/globals.h"
# include <ctype.h>
# include <dirent.h>

typedef struct s_concat
{
	char	*prefix;
	char	*body;
	char	*suffix;
}	t_concat;

char	*get_var_val(const char *str, char **env);
void	get_var_loc(char *str, char *save[2]);
char	*insert(char *str, char *start, char *end, char *to_insert);
char	*expand_var(char *str, char **env);
char	*get_body(const char *str, char *quote, size_t *i);
char	*get_prefix(const char *str, char *quote, size_t *i);
char	*concat_expand(const char *str, size_t i, char **env, char q);
char	*expand_str(char *str, char **env);
char	*remove_escapes(char *str);
int		count_protected(char *str);
int		has_protected(char *str);
int		is_protected(char c);
#endif
