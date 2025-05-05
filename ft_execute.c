/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:37:20 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/01/06 16:08:37 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit((ft_printf_fd(2, "Malloc failed\n") * 0) + EXIT_FAILURE);
	path = ft_get_path(cmd, env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_free_split(s_cmd);
		ft_printf_fd(2, "command not found: %s\n", cmd);
		exit(127);
	}
}
