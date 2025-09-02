/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:24:57 by aokur             #+#    #+#             */
/*   Updated: 2025/09/02 16:27:06 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char	*list = get_next_line(fd);
	while (list)
	{
		printf("%s", list);
		free(list);
		list = get_next_line(fd);
	}
	return (0);
}