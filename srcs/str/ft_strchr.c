/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:00:38 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 18:23:44 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strchr(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] != (char)n)
		i++;
	if (str[i] == (char)n)
		return ((char *)(str + i));
	return (NULL);
}
