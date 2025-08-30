/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:15:02 by aokur             #+#    #+#             */
/*   Updated: 2025/08/28 19:51:05 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	/*while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}*/
	close(fd);
	return 0;
}
