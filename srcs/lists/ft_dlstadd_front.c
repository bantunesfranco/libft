/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:25:56 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/05 16:45:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*head;

	head = NULL;
	if (*lst)
	{
		head = *lst;
		new->next = head;
		new->next->prev = new;
	}
	*lst = new;
}
