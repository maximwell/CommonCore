/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:15 by mmarhic           #+#    #+#             */
/*   Updated: 2024/10/22 23:38:52 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_sp(int nb, int count)
{
	unsigned int	num;

	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", count);
		return;
	}
	else if (num < 0)
	{
		ft_putchar_sp('-', count);
		ft_putnbr_sp(-num, count);
	}
	else
	{
		if (num > 9)
			ft_putnbr_sp((num / 10), count);
		ft_putchar_sp(('0' + num % 10), count);
	}
}
