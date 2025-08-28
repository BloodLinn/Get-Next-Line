/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:51 by aokur             #+#    #+#             */
/*   Updated: 2025/08/28 19:44:39 by aokur            ###   ########.fr       */
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
		 tmp = gnl_calloc(1, sizeof(char));
		if (tmp)
			tmp[0] = '\0';
		return (tmp);
	}
	tmp = gnl_calloc((len + 1) , sizeof(char));
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
	char	*tmp1;
	int		i;

	i = 0;
	while (gnl_strchr(lines, '\n'))
		i++;
	if (lines[i + 1] == '\n')
		i++;
	tmp1 = gnl_substr(lines, 0, i);
	return (tmp1);
}

char	*get_remains_line(char *lines)
{
	char	*tmp2;
	int		i;
	int		j;
	int		t;

	j = 0;
	i = 0;
	t = gnl_strlen(lines);
	while (gnl_strchr(lines, '\n'))
		i++;
	if (lines[i + 1] == '\n')
		i++;
	tmp2 = calloc((t - i + 1), sizeof(char));
	while (lines[i + j] != '\0')
	{
		tmp2[j] = lines[i + j];
		j++;
	}
	tmp2[j] = '\0';
	free(lines);
	return (tmp2);
}

char	*get_read_line(char *lines, int fd)
{
	char	line[BUFFER_SIZE + 1];
	ssize_t		count;

	count = 1;
	if (!lines)
		lines = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (gnl_strchr(lines, '\n') && count != 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == -1)
			return (free(lines), NULL);
		if (count == 0)
			break ;
		line[count] = '\0';
		lines = gnl_strjoin(line,lines);
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
