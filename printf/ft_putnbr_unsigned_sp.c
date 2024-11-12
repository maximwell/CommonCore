/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_sp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:27:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 20:45:05 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unsigned_sp(unsigned int num, int *count)
{
	if (num > 9)
		ft_putnbr_unsigned_sp(num / 10, count);
	ft_putchar_sp('0' + (num % 10), count);
}
