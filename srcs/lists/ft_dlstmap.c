/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstmap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:38:44 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/26 17:10:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, int (*f)(int))
{
	t_dlist	*newlist;
	t_dlist	*elem;

	if (!lst || !f)
		return (NULL);
	newlist = ft_dlstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	elem = newlist;
	while (lst->next)
	{
		lst = lst->next;
		elem->next = ft_dlstnew((*f)(lst->content));
		if (!(elem->next))
		{
			ft_dlstclear(&newlist);
			return (NULL);
		}
		elem = elem->next;
	}
	return (newlist);
}
