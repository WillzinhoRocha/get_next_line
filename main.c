/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:11:14 by wiferrei          #+#    #+#             */
/*   Updated: 2023/05/10 11:08:46 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	i = 1;
	if (fd < 0)
	{
		printf("Error opening file");
		return (0);
	}
	while ((line = get_next_line(fd)) > 0)
	{
		printf("Line %d:\n", i++);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
