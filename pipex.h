/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:40:35 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/01/06 12:32:10 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./lib/libft/libft.h"
# include <sys/wait.h>
# include <errno.h>

void	ft_child(char **av, int *p_fd, char **env);
void	ft_execute(char *cmd, char **env);
char	*ft_get_path(char *split_cmd, char **env);
void	ft_parent(char **av, int *p_fd, char **env);
char	*ft_strjoin_gnl(char *s1, char const *s2);
void	ft_free_split(char **s);

#endif