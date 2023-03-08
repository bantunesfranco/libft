/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 12:06:53 by bfranco       #+#    #+#                 */
/*   Updated: 2022/10/22 12:06:53 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static t_print	*ft_initialise_tab(t_print *tab)
{
	tab->len = 0;
	tab->type = 0;
	return (tab);
}

static const char	*print_text(t_print *tab, const char *format)
{
	char	*next;
	int		size;

	next = ft_strchr(format, '%');
	if (next)
		size = next - format;
	else
		size = ft_strlen(format);
	if (write(1, format, size) == -1)
		return (NULL);
	tab->len += size;
	while (*format && *format != '%')
		format++;
	return (format);
}

static const char	*parser(t_print *tab, const char *format)
{
	char	*str;
	int		size;

	tab->type = *format;
	str = get_type(tab);
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (tab->type == 'c')
		size = 1;
	tab->len += size;
	if (write(1, str, size) == -1)
	{
		if (tab->type != 's' || ft_strnstr(str, "(null)", 6))
			free(str);
		return (NULL);
	}
	if (tab->type != 's' || ft_strnstr(str, "(null)", 6))
		free(str);
	return (++format);
}

static int	read_input(t_print *tab, const char *format)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			format++;
		if (*format == '%')
			format = parser(tab, format + 1);
		else
			format = print_text(tab, format);
		if (!format)
			return (va_end(tab->args), free(tab), -1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		printed;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	printed = read_input(tab, format);
	if (printed == -1)
		return (-1);
	va_end(tab->args);
	printed = tab->len;
	free(tab);
	return (printed);
}
