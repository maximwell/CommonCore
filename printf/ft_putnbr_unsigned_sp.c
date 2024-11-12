/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_sp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:27:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 18:27:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_unisgned_sp(int num, int count)
{
	if (num > 9)
		ft_putnbr_unisgned_sp((num / 10), count);
	ft_putnbr_unisgned_sp(('0' + num % 10), count);
}