/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:19:32 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 17:59:16 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:19:32 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 16:36:30 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_hex(unsigned long long addr, int *count)
{
	char	buffer[16];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (addr > 0)
	{
		buffer[i++] = base[addr % 16];
		addr /= 16;
	}
	while (--i >= 0)
		ft_putchar_sp(buffer[i], count);
}

void	ft_putptr_sp(void *ptr, int *count)
{
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (addr == 0)
	{
		ft_putstr_sp("(nil)", count);
		return ;
	}
	ft_putstr_sp("0x", count);
	write_hex(addr, count);
}
