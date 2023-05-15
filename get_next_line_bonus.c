/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:14:17 by wiferrei          #+#    #+#             */
/*   Updated: 2023/05/11 08:50:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*ln;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		i = -1;
		while (buffer[fd][++i])
			buffer[fd][i] = 0;
		return (NULL);
	}
	ln = NULL;
	while (i > 0)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			ln = ft_strjoin(ln, buffer[fd]);
		if (ft_find_nl(buffer[fd]) > 0)
			break ;
	}
	return (ln);
}
