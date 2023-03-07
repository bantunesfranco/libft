/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnumber.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 17:07:51 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/11 11:13:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' && i == 0)
			i++;
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
