/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:41:29 by mmarhic           #+#    #+#             */
/*   Updated: 2024/11/12 21:03:13 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexa(char *c, int count, char check)
{
	int		i;
	char	*hex_digits_lower;
	char	*hex_digits_upper;

	hex_digits_lower = "0123456789abcdef";
	hex_digits_upper = "0123456789ABCDEF";
	i = 0;
	if (check == 'x')
	{
		while (c[i] != '\0')
		{
			ft_putchar_sp(hex_digits_lower[c[i] / 16], count);
			ft_putchar_sp(hex_digits_lower[c[i] % 16], count);
			i++;
		}
	}
	else
	{
		while (c[i] != '\0')
		{
			ft_putchar_sp(hex_digits_upper[c[i] / 16], count);
			ft_putchar_sp(hex_digits_upper[c[i] % 16], count);
			i++;
		}
	}
}
