/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 14:20:25 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/08 12:22:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static char	*ft_string(char *str)
{
	if (!str)
		str = ft_strdup("(null)");
	return (str);
}

char	*chartostr(int c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	return (str);
}

char	*get_type(t_print *tab)
{
	char	*str;

	if (tab->type == 'c')
		str = chartostr(va_arg(tab->args, int));
	else if (tab->type == 's')
		str = ft_string(va_arg(tab->args, char *));
	else if (tab->type == 'x' || tab->type == 'X')
		str = ft_itoa_hex(va_arg(tab->args, unsigned int), tab->type);
	else if (tab->type == 'p')
		str = ft_itoa_ptr((unsigned long int)va_arg(tab->args, void *));
	else if (tab->type == 'd' || tab->type == 'i')
		str = ft_itoa(va_arg(tab->args, int));
	else if (tab->type == 'u')
		str = ft_itoa_uint(va_arg(tab->args, unsigned int));
	else if (tab->type == '%')
		str = ft_strdup("%");
	else
		str = chartostr(tab->type);
	if (!str)
		return (NULL);
	return (str);
}
