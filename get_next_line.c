/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:55:21 by gkehren           #+#    #+#             */
/*   Updated: 2022/04/13 02:44:55 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	char	*line;
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	line = (char *)malloc(sizeof(char));
	while (ft_strchr(temp, '\n') == 0)
	{
		read(fd, temp, BUFFER_SIZE);
		if (ft_strchr(temp, '\n') == 0)
			line = ft_strjoin(line, temp);
	}
	if (ft_strchr(temp, '\n') == 1)
		line = ft_strjoin(line, temp);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i + 1] = '\0';
		i++;
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*c;

	if (fd == -1)
		return (NULL);
	c = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	c = get_line(fd);
	return (c);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}*/
