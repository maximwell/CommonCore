/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:18:22 by mmarhic           #+#    #+#             */
/*   Updated: 2025/04/23 16:17:12 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	parse_decimal(const char *str, double *fracpart, double *div)
{
	while (*str >= '0' && *str <= '9')
	{
		*fracpart = *fracpart * 10.0 + (*str - '0');
		*div *= 10.0;
		str++;
	}
}

static void	parse_sign(const char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

static void	parse_intpart(const char **str, double *intpart)
{
	while (**str >= '0' && **str <= '9')
	{
		*intpart = *intpart * 10.0 + (**str - '0');
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	int		sign;
	double	intpart;
	double	fracpart;
	double	div;

	sign = 1;
	intpart = 0.0;
	fracpart = 0.0;
	div = 1.0;
	parse_sign(&str, &sign);
	parse_intpart(&str, &intpart);
	if (*str == '.')
	{
		str++;
		parse_decimal(str, &fracpart, &div);
	}
	return (sign * (intpart + fracpart / div));
}
