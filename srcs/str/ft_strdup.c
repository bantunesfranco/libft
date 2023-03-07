/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:37:09 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 18:23:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(str);
	dest = malloc(size + 1);
	if (!dest)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(dest, str, size + 1);
	return (dest);
}
