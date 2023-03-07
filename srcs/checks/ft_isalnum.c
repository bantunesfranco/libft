/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:52:06 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:49:36 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_isalnum(int n)
{
	return (ft_isdigit(n) || ft_isalpha(n));
}
