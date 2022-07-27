/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:11:46 by awallet           #+#    #+#             */
/*   Updated: 2022/07/19 21:47:02 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > MAX_FD)
		return (1);
	return (0);
}

static char	*ft_extract(char *line)
{
	size_t	i;
	char	*stock;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stock == '\0')
	{
		free(stock);
		stock = NULL;
	}
	line[i + 1] = '\0';
	return (stock);
}

static char	*ft_read(int fd, char *buffer, char *stock[fd])
{
	ssize_t		nbytes;
	char		*temp;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		if (!stock[fd])
			stock[fd] = ft_strdup("");
		temp = stock[fd];
		stock[fd] = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stock[fd]);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stock[MAX_FD];

	if (ft_error(fd))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, stock);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stock[fd] = ft_extract(line);
	return (line);
}
