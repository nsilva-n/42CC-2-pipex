/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:38:24 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/01/07 13:21:56 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (ac != 5)
		exit((ft_printf_fd(2, "Need 5 args\n") * 0) + EXIT_FAILURE);
	if (pipe(p_fd) == -1)
		exit((ft_printf_fd(2, "Pipe failed\n") * 0) + EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit((ft_printf_fd(2, "Fork failed\n") * 0) + EXIT_FAILURE);
	if (!pid)
		ft_child(av, p_fd, env);
	ft_parent(av, p_fd, env);
	exit(EXIT_SUCCESS);
}
