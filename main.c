/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:28:36 by aokur             #+#    #+#             */
/*   Updated: 2025/09/05 20:30:19 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *ali = get_next_line(fd);
	while(ali)
	{
		printf("%s", ali);
		free(ali);
		ali = get_next_line(fd);
	}
	close(fd);
	return (0);
}
