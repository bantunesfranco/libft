/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:38:03 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 18:23:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	mem = malloc(s1_len + s2_len + 1);
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, (s1_len + 1));
	ft_memcpy(mem + s1_len, s2, (s2_len + 1));
	return (mem);
}
