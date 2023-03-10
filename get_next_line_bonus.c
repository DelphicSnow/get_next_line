/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:20:42 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/09 14:55:08 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*store_leftovers(char *static_buff)
{
	char		*leftovers;
	int			i;

	i = 0;
	while (static_buff[i] && !(static_buff[i] == '\n'))
		i++;
	if (!static_buff[i])
	{
		free(static_buff);
		return (NULL);
	}
	i++;
	leftovers = ft_strdup(static_buff + i, (ft_strlen(static_buff) - i));
	if (static_buff != NULL)
		free (static_buff);
	return (leftovers);
}

char	*get_line(char *static_buff)
{
	char		*s1;
	int			i;

	i = 0;
	if (!static_buff[i])
		return (NULL);
	while (static_buff[i] && !(static_buff[i] == '\n'))
		i++;
	if (static_buff[i])
		i++;
	s1 = ft_strdup(static_buff, i);
	return (s1);
}

char	*allocating_read_buffer(char *static_buff, int fd)
{
	int		r;
	char	*read_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	r = 1;
	while (r > 0 && !ft_strchr(static_buff, '\n'))
	{
		r = read(fd, read_buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[r] = '\0';
		static_buff = ft_strjoin(static_buff, read_buffer);
	}
	free (read_buffer);
	return (static_buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buff[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	static_buff[fd] = allocating_read_buffer(static_buff[fd], fd);
	if (static_buff[fd] == NULL)
		return (NULL);
	line = get_line(static_buff[fd]);
	static_buff[fd] = store_leftovers(static_buff[fd]);
	return (line);
}
/*
#include <stdio.h>
# include <fcntl.h>

int	main (int argc, char **argv)
 {
	int		fd;
	char	*line;


	if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return (-1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}

    while ((line = get_next_line(fd)))
	{
        printf("%s", line);
        free(line);
    }
	
	close(fd);
	return (0);
}
*/