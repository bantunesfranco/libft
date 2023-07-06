/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 10:06:04 by bfranco       #+#    #+#                 */
/*   Updated: 2022/10/19 10:06:04 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"
#include <limits.h>

static char	*get_new_line(char **to_read)
{
	int		i;
	char	*line;
	char	*tmp;

	if (!**to_read)
		return (NULL);
	i = 0;
	while ((*to_read)[i] != '\n' && (*to_read)[i])
		i++;
	if (ft_strchr(*to_read, '\n'))
		line = ft_substr(*to_read, 0, i + 1);
	else
		line = ft_strdup(*to_read);
	if (!line)
		return (NULL);
	tmp = *to_read;
	*to_read = ft_substr(*to_read, i + 1, ft_strlen(*to_read) - i);
	free(tmp);
	if (!tmp)
	{
		*to_read = NULL;
		return (NULL);
	}
	return (line);
}

static char	*get_to_read(int fd, char *to_read)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (!ft_strchr(to_read, '\n') && bytes_read != 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (read(fd, 0, 0) == -1 || bytes_read == -1)
		{
			free(to_read);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		tmp = to_read;
		to_read = ft_strjoin(to_read, buff);
		free(tmp);
		if (!to_read)
			return (NULL);
	}
	return (to_read);
}

char	*get_next_line(int fd)
{
	static char	*to_read = NULL;
	char		*line;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0 \
	|| BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!to_read)
	{
		to_read = ft_calloc(1, 1);
		if (!to_read)
			return (NULL);
	}
	to_read = get_to_read(fd, to_read);
	if (!to_read)
		return (NULL);
	line = get_new_line(&to_read);
	if (!line)
	{
		free(to_read);
		to_read = NULL;
		return (NULL);
	}
	return (line);
}
