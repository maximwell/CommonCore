/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:32:17 by mmarhic           #+#    #+#             */
/*   Updated: 2024/11/29 16:38:25 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexa_char(unsigned int num, int *count, char check)
{
	char	*hex_digits;

	if (check == 'x')
		hex_digits = "0123456789abcdef";
	else if (check == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthexa_char(num / 16, count, check);
	ft_putchar_sp(hex_digits[num % 16], count);
}

int	ft_puthexa(unsigned int num, int *count, char check)
{
	ft_puthexa_char(num, count, check);
	return (*count);
}
