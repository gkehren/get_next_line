/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:55:21 by gkehren           #+#    #+#             */
/*   Updated: 2022/04/14 01:28:26 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_line(int fd, char *file)
{
	char	*line;
	int		bytes;

	bytes = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (ft_strchr(file, '\n') == 0 && bytes != 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			return (NULL);
		}
		line[bytes] = '\0';
		file = ft_strjoin(file, line);
	}
	free(line);
	return (file);
}

char	*get_line(char *file)
{
	int		i;
	char	*temp;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * i + 2);
	if (!file)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
	{
		temp[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		temp[i] = file[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_new_file(char *file)
{
	int		i;
	char	*temp;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(file) - i + 1));
	if (!temp)
		return (NULL);
	temp = ft_strcpy(temp, file+i+1);
	free(file);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*file;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = get_read_line(fd, file);
	if (!file)
		return (NULL);
	line = get_line(file);
	file = get_new_file(file);
	return (line);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;
	char *line;
	int i = 1;
	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/
