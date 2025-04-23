/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:06:47 by mmarhic           #+#    #+#             */
/*   Updated: 2025/04/23 16:18:59 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot_vars(int x, int y, t_data *data,
		double vars[6])
{
	vars[0] = (x - data->width / 2.0) / (0.5 * data->zoom * data->width)
		+ data->offset_x;
	vars[1] = (y - data->height / 2.0) / (0.5 * data->zoom * data->height)
		+ data->offset_y;
	vars[2] = 0.0;
	vars[3] = 0.0;
	vars[4] = 0.0;
	vars[5] = 0.0;
}

int	mandelbrot(int x, int y, t_data *data)
{
	double	vars[6];
	int		iter;

	init_mandelbrot_vars(x, y, data, vars);
	iter = 0;
	while (vars[4] + vars[5] <= 4.0 && iter < data->max_iter)
	{
		vars[3] = 2.0 * vars[2] * vars[3] + vars[1];
		vars[2] = vars[4] - vars[5] + vars[0];
		vars[4] = vars[2] * vars[2];
		vars[5] = vars[3] * vars[3];
		iter++;
	}
	if (iter == data->max_iter)
		return (0x000000);
	return ((int)(0xFFFFFF * iter / data->max_iter));
}
