/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:38:44 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 17:49:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	elem = newlist;
	while (lst->next)
	{
		lst = lst->next;
		elem->next = ft_lstnew((*f)(lst->content));
		if (!(elem->next))
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		elem = elem->next;
	}
	return (newlist);
}
