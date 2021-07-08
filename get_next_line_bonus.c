/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:00:16 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/07/07 22:16:31 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_search_nl(char *buff)
{
	if (!(buff))
		return (0);
	while (*buff != 0)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

char	*ft_save_line(char *storage_read, char **line, int bytes)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (storage_read[i] != '\n' && storage_read[i] != '\0')
		i++;
	storage_read[i] = '\0';
	*line = ft_strdup(storage_read);
	if (!*line)
		return (0);
	if (bytes != 0)
	{
		temp = ft_strdup(storage_read + i + 1);
		if (!temp)
			return (0);
	}
	free(storage_read);
	return (temp);
}

int	ft_read_line(int fd, char **storage_read, char *buff, int *bytes)
{
	while (*bytes && !(ft_search_nl(*storage_read)))
	{
		*bytes = read(fd, buff, BUFFER_SIZE);
		if (*bytes < 0)
		{
			free(buff);
			return (0);
		}
		buff[*bytes] = '\0';
		*storage_read = ft_strjoin(*storage_read, buff);
	}
	free(buff);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage_read[RLIMIT_NOFILE];
	char		*buff;
	int			bytes;

	bytes = 1;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	if (!storage_read[fd])
		storage_read[fd] = ft_strdup("");
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!(ft_read_line(fd, &storage_read[fd], buff, &bytes)))
		return (-1);
	storage_read[fd] = ft_save_line(storage_read[fd], line, bytes);
	if (!(bytes))
		return (0);
	return (1);
}
