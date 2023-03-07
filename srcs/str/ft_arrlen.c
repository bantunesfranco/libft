/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:19:28 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/26 17:10:29 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
