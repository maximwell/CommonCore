/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:10:59 by mmarhic           #+#    #+#             */
/*   Updated: 2024/11/12 22:50:42 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_checking(const char check, va_list va, int *count)
{
	if (check == 'c')
		ft_putchar_sp(va_arg(va, int), count);
	else if (check == 's')
		ft_putstr_sp(va_arg(va, char *), count);
	else if (check == 'p')
		ft_putptr_sp(va_arg(va, void *), count);
	else if (check == 'd' || check == 'i')
		ft_putnbr_sp(va_arg(va, int), count);
	else if (check == 'u')
		ft_putnbr_unsigned_sp(va_arg(va, int), count);
	else if (check == '%')
		ft_putchar_sp(check, count);
	else if (check == 'x' || check == 'X')
		ft_puthexa(va_arg(va, unsigned int), count, check);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	if (!format)
		return (0);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_checking(format[i], args, &count);
		}
		else
			ft_putchar_sp(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
