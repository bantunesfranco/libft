/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 19:28:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/13 11:44:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static char	*get_uint(char *str, unsigned int nb, int pos)
{
	str[pos] = '\0';
	while (nb > 9 || pos)
	{
		pos--;
		str[pos] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa_uint(unsigned int n)
{
	int		i;
	char	*str;

	i = ft_uintlen(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	return (get_uint(str, n, i));
}
