/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:36:00 by mmarhic           #+#    #+#             */
/*   Updated: 2024/11/12 22:55:39 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_sp(char c, int *count);
void	ft_putnbr_sp(int nb, int *count);
void	ft_putnbr_unsigned_sp(unsigned int num, int *count);
void	ft_putptr_sp(void *ptr, int *count);
void	ft_putstr_sp(char *s, int *count);
int		ft_puthexa(unsigned int i, int *count, char check);

#endif