/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstfirst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:13:56 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/03 16:07:54 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
