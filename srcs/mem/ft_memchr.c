/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:01:54 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:52:08 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memchr(const void *p, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_cpy;

	i = 0;
	p_cpy = (unsigned char *)p;
	while (n--)
	{
		if (p_cpy[i] == (unsigned char)c)
			return ((void *)p + i);
		i++;
	}
	return (NULL);
}
