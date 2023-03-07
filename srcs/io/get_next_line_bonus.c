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

static char	*get_new_left(char *to_read)
{
	int		i;
	int		j;
	char	*new_read;

	if (!to_read)
		return (NULL);
	i = 0;
	j = 0;
	while (to_read[i] != '\n' && to_read[i])
		i++;
	if (ft_strchr(to_read, '\n'))
		i++;
	if (!to_read[i])
		return (free(to_read), NULL);
	new_read = (char *)malloc(sizeof(char) * (ft_strlen(to_read) - i + 1));
	if (!new_read)
		return (free(to_read), NULL);
	while (to_read[i])
		new_read[j++] = to_read[i++];
	new_read[j] = '\0';
	return (free(to_read), new_read);
}

static char	*get_new_line(char *to_read)
{
	int		i;
	int		j;
	char	*line;

	if (!to_read[0])
		return (NULL);
	i = 0;
	while (to_read[i] != '\n' && to_read[i])
		i++;
	if (ft_strchr(to_read, '\n'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(to_read), NULL);
	i = 0;
	j = 0;
	while (to_read[i] != '\n' && to_read[i])
		line[i++] = to_read[j++];
	if (to_read[i] == '\n')
		line[i++] = to_read[j++];
	line[i] = '\0';
	return (line);
}

static char	*get_to_read(int fd, char *to_read)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(to_read, '\n') && bytes_read != 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1 || read(fd, 0, 0) == -1)
			return (free(buff), free(to_read), NULL);
		if (bytes_read == 0)
		{
			free(buff);
			break ;
		}
		buff[bytes_read] = '\0';
		to_read = ft_strjoin_free(to_read, buff);
		if (!to_read)
			return (NULL);
	}
	return (to_read);
}

char	*get_next_line(int fd)
{
	static char	*to_read[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!to_read[fd])
	{
		to_read[fd] = (char *)malloc(1);
		if (!to_read[fd])
			return (NULL);
		to_read[fd][0] = '\0';
	}
	to_read[fd] = get_to_read(fd, to_read[fd]);
	if (!to_read[fd])
		return (NULL);
	line = get_new_line(to_read[fd]);
	if (!line && ft_strlen(to_read[fd]))
		return (free(to_read[fd]), line);
	to_read[fd] = get_new_left(to_read[fd]);
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