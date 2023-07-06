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
	static char	*to_read[4096];
	char		*line;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0 \
	|| BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!to_read[fd])
	{
		to_read[fd] = ft_calloc(1, 1);
		if (!to_read[fd])
			return (NULL);
	}
	to_read[fd] = get_to_read(fd, to_read[fd]);
	if (!to_read[fd])
		return (NULL);
	line = get_new_line(&to_read[fd]);
	if (!line)
	{
		free(to_read[fd]);
		to_read[fd] = NULL;
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("sw.txt", O_RDONLY);
// 	fd2 = open("hello.txt", O_RDONLY);
// 	fd3 = open("text.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 25)
// 	{
// 		line = get_next_line(fd1);
// 		printf("fd1 line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("fd2 line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("fd3 line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }