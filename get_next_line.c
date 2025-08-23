/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:51 by aokur             #+#    #+#             */
/*   Updated: 2025/08/23 19:58:59 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_line(char *lines, int fd)
{
	char	*line;
	int		count;

	if (!lines)
	{
		lines = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		lines[0] = '\0';
		return (lines);
	}
	line = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(gnl_strchr(lines, '\n'))
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == -1)
			return (free(lines), free(line), NULL);
		line[count] = '\0';
		lines = gnl_strjoin(lines, line);
	}
	free(line);
	return (line);
}

char *get_next_line(int fd)
{
	static char	*lines;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = read_line(lines, fd);
	if (!lines)
		return (NULL);
}
