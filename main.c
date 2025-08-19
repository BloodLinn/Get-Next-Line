/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:15:24 by aokur             #+#    #+#             */
/*   Updated: 2025/08/19 17:27:42 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdlib.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	b;
	char	*tmp;

	l = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc(((ft_strlen(s1)) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!tmp)
		return (NULL);
	while (s1[l])
	{
		tmp[l] = s1[l];
		l++;
	}
	while (s2[b])
	{
		tmp[l + b] = s2[b];
		b++;
	}
	tmp[l + b] = '\0';
	return (tmp);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
	int		fd; 
	char	*line = malloc(BUFFER_SIZE);
	static char	*tmp;
	int		x;
	
	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	while ((read(fd, line, BUFFER_SIZE)))
	{
		tmp = ft_strjoin(line, tmp);

	}








	printf("%s", tmp);
	close(fd);
	free(line);
	free(tmp);
	return 0;
}
