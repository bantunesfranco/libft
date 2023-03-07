/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:14:59 by bfranco       #+#    #+#                 */
/*   Updated: 2023/01/02 18:24:33 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1);
	while (end != start && ft_strrchr(set, s1[end - 1]))
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (0);
	while (i < end - start)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
