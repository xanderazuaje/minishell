/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:58:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/13 16:59:04 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_executor.h"

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
	if (ft_strchr(program, '/') != NULL || ft_strncmp(program, "..", 3) == 0 || ft_strncmp(program, ".", 2) == 0)
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
