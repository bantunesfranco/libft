/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstiter.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:33:49 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/26 17:11:51 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dlstiter(t_dlist *lst, int (*f)(int))
{
	while (lst)
	{
		if (!f)
			return ;
		(*f)(lst->content);
		lst = lst->next;
	}
}
