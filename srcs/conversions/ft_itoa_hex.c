/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 19:28:15 by bfranco       #+#    #+#                 */
/*   Updated: 2022/10/21 19:28:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static char	*get_hex(char *str, unsigned int nb, int pos, char *base)
{
	str[pos] = '\0';
	while (nb > 15 || pos)
	{
		pos--;
		str[pos] = base[nb % 16];
		nb = nb / 16;
	}
	return (str);
}

char	*ft_itoa_hex(unsigned int n, char type)
{
	int		i;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	i = ft_hexlen(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	return (get_hex(str, n, i, base));
}
