/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:15 by mmarhic           #+#    #+#             */
/*   Updated: 2024/11/12 22:21:37 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_sp(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr_sp("-2147483648", count);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar_sp('-', count);
		ft_putnbr_sp(-nb, count);
	}
	else
	{
		if (nb > 9)
			ft_putnbr_sp((nb / 10), count);
		ft_putchar_sp(('0' + nb % 10), count);
	}
}
