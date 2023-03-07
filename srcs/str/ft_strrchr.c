/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 08:07:30 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 18:24:31 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strrchr(const char *s, int n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (i > 0 && str[i] != (char)n)
		i--;
	if (str[i] == (char)n)
		return ((char *)(str + i));
	return (NULL);
}
