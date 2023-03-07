/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstdelone.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:03:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/03 16:07:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dlstdelone(t_dlist *lst)
{
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}
