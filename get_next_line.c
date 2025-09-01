/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:51 by aokur             #+#    #+#             */
/*   Updated: 2025/09/01 20:11:37 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*tmp;
	size_t	i;

	i = 0;
	a = gnl_strlen(s);
	if (a < start + len)
		len = a - start;
	if (start >= a)
	{
		tmp = malloc(1 *sizeof(char));
		if (tmp)
			tmp[0] = '\0';
		return (tmp);
	}
	tmp = malloc((len + 1) *sizeof(char));
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_first_line(char *lines)
{
	int	i;

	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	return (gnl_substr(lines, 0, i));
}

char	*get_remains_line(char *lines)
{
	int		i;
	int		t;
	char	*tmp2;

	if (!lines)
		return(NULL);
	i = 0;
	t = gnl_strlen(lines);
	if (lines == NULL)
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
		return (free(lines), NULL);
	i++;
	tmp2 = gnl_substr(lines, i, t - i);
	free(lines);
	return (tmp2);
}

char	*get_read_line(char *lines, int fd)
{
	char	line[BUFFER_SIZE + 1];
	ssize_t		count;

	count = 1;
	if (!lines)
		lines = gnl_calloc((BUFFER_SIZE + 1) ,sizeof(char));
	while (!gnl_strchr(lines, '\n') && count > 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		line[count] = 0;
		if (count == -1)
			return (free(lines), NULL);
		lines = gnl_strjoin(lines,line);
	}
	if (gnl_strlen(lines)== 0)
	{
		free(lines);
		return NULL;
	}
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*first;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = get_read_line(lines, fd);
	if (!lines)
		return (NULL);
	first = get_first_line(lines);
	lines = get_remains_line(lines);
	return (first);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s" ,line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		
	}
	
	return 0;
}
