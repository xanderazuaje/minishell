/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/23 13:09:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:49:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/08/29 13:47:55 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"

int		g_exit_status = 0;

void	set_line(char **line)
{
	if (isatty(STDIN_FILENO))
		*line = readline("\033[0;33mbASSh> \033[0;0m");
	else
		*line = readline("");
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_cmdlist	*cmds;

	env = envcopy(env);
	(void ) argc;
	(void ) argv;
	init_signals();
	while (1)
	{
		set_line(&line);
		if (line && *line)
			add_history(line);
		if (!line)
		{
			free(line);
			freeenv(&env);
			exit(g_exit_status);
		}
		cmds = parse_str(line, env);
		executor(cmds, &env);
		free_cmd(cmds);
		free(line);
	}
}
