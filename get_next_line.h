/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:34 by aokur             #+#    #+#             */
/*   Updated: 2025/09/05 20:32:54 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_read_line(char *line, int fd);
char	*get_first_line(char *lines);
char	*get_remains_line(char *lines);
int		gnl_strlen(char	*dest);
char	*gnl_strcpy(char *dest, char *src);
char	*gnl_strchr(char *s, int c);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif