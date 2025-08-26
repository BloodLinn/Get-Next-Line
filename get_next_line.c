/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:11:51 by aokur             #+#    #+#             */
/*   Updated: 2025/08/26 20:09:36 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*tmp;
	size_t	i;

	i = 0;
	a = ft_strlen(s);
	if (a < start + len)
		len = a - start;
	if (start >= a)
		return (ft_strdup(""));
	tmp = malloc((len + 1) * sizeof(char));
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
	char	*tmp;
	int		i;

	while (gnl_strchr(lines, '\n'))
		i++;
	if (lines == '\n')
		i++;
	tmp = calloc((i + 1),sizeof(char));
	gnl_substr(tmp,0,i);
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*get_remains_line(char *lines)
{
	
}

char	*get_read_line(char *lines, int fd)
{
	char	line[BUFFER_SIZE + 1];
	ssize_t		count;

	if (!lines)
	{
		lines = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		lines[0] = '\0';
		return (lines);
	}
	while(gnl_strchr(lines, '\n') && count != 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == -1)
			return (free(lines), free(line), NULL);
		line[count] = '\0';
		lines = gnl_strjoin(line,lines);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = get_read_line(lines, fd);
	if (!lines)
		return (NULL);
	return (lines);
}
