/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:28:10 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/01/06 16:10:21 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*name;
	char	**split_cmd;

	i = -1;
	name = NULL;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	all_paths = ft_split(env[i] + 5, ':');
	split_cmd = ft_split(cmd, ' ');
	if (!all_paths || !split_cmd)
		exit((ft_printf_fd(2, "Malloc failed\n") * 0) + EXIT_FAILURE);
	i = -1;
	while (all_paths[++i])
	{
		name = ft_strjoin(all_paths[i], "/");
		name = ft_strjoin_gnl(name, split_cmd[0]);
		if (!access(name, F_OK | X_OK))
			return (ft_free_split(split_cmd), name);
		free(name);
	}
	return (ft_free_split(all_paths), ft_free_split(split_cmd), cmd);
}
