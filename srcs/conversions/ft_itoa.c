/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 09:42:01 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/09 14:45:41 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	get_len(int n)
{
	int				i;
	long long int	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i = 2;
	}
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static char	*get_str(char *str, int n, int pos)
{
	long long int	nb;
	int				limit;

	nb = n;
	limit = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		limit = 1;
	}
	str[pos] = '\0';
	while (nb > 9 && pos >= limit)
	{
		pos--;
		str[pos] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[pos - 1] = nb + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = get_len(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	return (get_str(str, n, i));
}
