/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:19:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 22:35:27 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_sp(void *ptr, int *count)
{
	unsigned long long	adress;
	char				*hex_digits;
	char				buffer[16];
	int					i;

	hex_digits = "0123456789abcdef";
	adress = (unsigned long long)ptr;
	if (adress == 0)
	{
		ft_putstr_sp("(nil)", count);
		return ;
	}
	ft_putstr_sp("0x", count);
	if (adress == 0)
	{
		ft_putchar_sp('0', count);
		return ;
	}
	i = 0;
	while (adress > 0)
	{
		buffer[i++] = hex_digits[adress % 16];
		adress /= 16;
	}
	while (i > 0)
	{
		ft_putchar_sp(buffer[--i], count);
	}
}
