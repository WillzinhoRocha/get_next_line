/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:22:56 by wiferrei          #+#    #+#             */
/*   Updated: 2023/05/15 10:06:36 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		i;
	char	*line;

	fd1 = open("example.txt", O_RDONLY);
	fd2 = open("example2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("Error opening file(s)\n");
		return (0);
	}
	i = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %d (File 1):\n", i++);
		printf("%s\n", line);
		free(line);
	}
	i = 1;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %d (File 2):\n", i++);
		printf("%s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}
