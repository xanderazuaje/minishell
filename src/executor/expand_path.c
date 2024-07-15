/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:58:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 07:19:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

int	is_path(const char *p)
{
	return (ft_strchr(p, '/') != NULL || ft_strncmp(p, "..", 3) == 0
		|| ft_strncmp(p, ".", 2) == 0);
}

char	*get_path_route(const char *program, t_splitted **routes)
{
	char	*path;
	char	*prev;
	size_t	i;
	int		status;

	i = 0;
	path = NULL;
	while ((*routes) && i < (*routes)->len)
	{
		prev = ft_strjoin("/", program);
		if (!prev)
			break ;
		path = ft_strjoin((*routes)->string[i], prev);
		free(prev);
		if (!path)
			break ;
		status = access(path, X_OK);
		if (status == 0)
			return (free_splitted(routes), path);
		free(path);
		i++;
	}
	free_splitted(routes);
	return (NULL);
}

char	*expand_path(const char *program, char **env)
{
	t_splitted	*routes;

	if (program == NULL)
		return (NULL);
	routes = NULL;
	if (is_path(program))
		return (ft_strdup(program));
	while (*env)
	{
		if (start_with(*env, "PATH"))
		{
			routes = ft_split(*env + 5, ':');
			if (routes == NULL)
				return (NULL);
		}
		env++;
	}
	return (get_path_route(program, &routes));
}
