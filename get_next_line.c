/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:51 by aokur             #+#    #+#             */
/*   Updated: 2025/09/07 17:52:13 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	i;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	a = gnl_strlen(s);
	if (start >= a)
		return (gnl_calloc(1, sizeof(char)));
	if (a < start + len)
		len = a - start;
	tmp = gnl_calloc((len + 1), sizeof(char));
	if (!tmp)
		return (NULL);
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
	int		i;
	char	*tmp1;

	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	tmp1 = gnl_substr(lines, 0, i);
	return (tmp1);
}

char	*get_remains_line(char *lines)
{
	int		i;
	int		t;
	char	*tmp2;

	if (!lines)
		return (NULL);
	i = 0;
	t = gnl_strlen(lines);
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
	char	*line;
	ssize_t	count;
	char	*tmp;

	count = 1;
	if (!lines)
		lines = gnl_calloc(1, 1);
	line = gnl_calloc((BUFFER_SIZE + 1), 1);
	if (!line || !lines)
		return (free(lines), free(line), NULL);
	while (!gnl_strchr(lines, '\n') && count > 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == -1)
			return (free(lines), free(line), NULL);
		line[count] = 0;
		tmp = lines;
		lines = gnl_strjoin(lines, line);
		free(tmp);
	}
	if (gnl_strlen (lines) == 0)
		return (free(lines), free(line), NULL);
	free(line);
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
