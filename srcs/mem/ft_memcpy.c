/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:40:25 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:52:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	i = 0;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if ((dst == src) || !n)
		return (dst);
	while (n--)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
