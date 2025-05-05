/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:22:25 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/12/26 14:22:57 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen_nl(s1);
	j = ft_strlen_nl(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j] && j < ft_strlen_nl(s2))
		dest[i++] = s2[j];
	dest[i] = '\0';
	if (s1)
		free(s1);
	return (dest);
}
