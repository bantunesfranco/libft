/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 08:27:29 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/01 17:24:07 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdio.h>

void	ft_error(char *str, int err)
{
	errno = err;
	perror(str);
	exit(errno);
}
