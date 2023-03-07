/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 07:55:48 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:52:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	i = 0;
	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n -1 && s1_cpy[i] == s2_cpy[i])
		i++;
	return (s1_cpy[i] - s2_cpy[i]);
}
