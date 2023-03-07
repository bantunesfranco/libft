/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:21:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:49:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *lst;
	while (ptr)
	{
		if (!del)
			return ;
		ptr2 = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = ptr2;
	}
	*lst = NULL;
}
