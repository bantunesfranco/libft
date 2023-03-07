/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 22:33:59 by bfranco       #+#    #+#                 */
/*   Updated: 2022/10/18 22:33:59 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*mem;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	mem = malloc(s1_len + s2_len + 1);
	if (!mem)
		return (free(s1), free(s2), NULL);
	ft_memcpy(mem, s1, (s1_len + 1));
	ft_memcpy(mem + s1_len, s2, (s2_len + 1));
	return (free(s1), free(s2), mem);
}
