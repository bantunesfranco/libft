/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:08:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/06 16:07:10 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst)
	{
		last = ft_dlstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}
