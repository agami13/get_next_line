/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:26 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/28 13:35:49 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *cup)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(cup, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		cup = ft_strjoin(cup, buffer);
	}
	free(buffer);
	return (cup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cup = read_file(fd, cup);
	if (!cup)
		return (NULL);
	line = copy_line(cup);
	cup = new_line(cup);
	return (line);
}
#include <stdio.h>
int main()
{
 	int fd1;
 	char	*rs;
 	fd1 = open("test.txt", O_RDONLY);
 	// fd2 = open("test2.txt", O_RDONLY);
 	// fd3 = open("test3.txt", O_RDONLY);
 	while((rs = get_next_line(fd1)))
 		printf("%s", rs);
 	close (fd1);
}
