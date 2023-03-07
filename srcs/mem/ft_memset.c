/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 18:44:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:52:22 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_cpy;

	s_cpy = s;
	while (n > 0)
	{
		*s_cpy = c;
		s_cpy++;
		n--;
	}
	return (s);
}
