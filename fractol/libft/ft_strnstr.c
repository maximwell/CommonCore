/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:00:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 14:00:44 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*to_find)
		return ((char *)s);
	pos = 0;
	while (s[pos] && (size_t)pos < n)
	{
		if (s[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && s[pos + i] == to_find[i] && (size_t)(pos
				+ i) < n)
				i++;
			if (to_find[i] == '\0')
				return ((char *)&s[pos]);
		}
		pos++;
	}
	return (NULL);
}
