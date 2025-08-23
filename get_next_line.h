/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:34 by aokur             #+#    #+#             */
/*   Updated: 2025/08/23 19:49:09 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_read_line(char *line, int fd);
//char	*get_first_line(int fd);
//char	*get_remains_line(int fd);
char	*gnl_strcpy(char *dest, char *src);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif