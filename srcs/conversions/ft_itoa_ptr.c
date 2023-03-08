/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 19:28:15 by bfranco       #+#    #+#                 */
/*   Updated: 2022/10/21 19:28:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	get_len(unsigned long int nb)
{
	int	i;

	i = 1;
	while (nb > 15)
	{
		i++;
		nb = nb / 16;
	}
	i += 2;
	return (i);
}

static char	*get_ptr(char *str, unsigned long int nb, int pos)
{
	char	*base;

	base = "0123456789abcdef";
	str[pos] = '\0';
	while (nb > 15 || pos > 1)
	{
		pos--;
		str[pos] = base[nb % 16];
		nb = nb / 16;
	}
	str[pos--] = base[nb];
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*ft_itoa_ptr(unsigned long int n)
{
	int		i;
	char	*str;

	i = get_len(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	return (get_ptr(str, n, i));
}
