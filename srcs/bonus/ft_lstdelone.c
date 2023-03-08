/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:03:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/02 11:48:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst || del)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}
