/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:14:25 by aokur             #+#    #+#             */
/*   Updated: 2025/09/05 20:10:15 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char	*dest)
{
	int	i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i])
		i++;
	return (i);
}

char	*gnl_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char )c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char )c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	l;
	size_t	b;
	char	*tmp;

	l = 0;
	b = 0;
	if (!s1 && !s2)
		return (NULL);
	tmp = gnl_calloc((((gnl_strlen(s1)) + gnl_strlen(s2) + 1)), (sizeof(char)));
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

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > 9223372036854775807 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}
