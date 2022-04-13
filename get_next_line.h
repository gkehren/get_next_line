/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:55:23 by gkehren           #+#    #+#             */
/*   Updated: 2022/04/14 01:14:06 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_new_file(char *file);
char	*get_line(char *file);
char	*get_read_line(int fd, char *file);
size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif
