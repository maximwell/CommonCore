/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:06:29 by mmarhic           #+#    #+#             */
/*   Updated: 2025/04/23 12:10:18 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

#define ZOOM_FACTOR 1.2

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	cx;
	double	cy;

	if (button == 4 || button == 5)
	{
		cx = (x - data->width / 2.0) / (0.5 * data->zoom * data->width)
			+ data->offset_x;
		cy = (y - data->height / 2.0) / (0.5 * data->zoom * data->height)
			+ data->offset_y;
		if (button == 4)
			data->zoom *= ZOOM_FACTOR;
		else
			data->zoom /= ZOOM_FACTOR;
		data->offset_x = cx - (x - data->width / 2.0) / (0.5 * data->zoom
				* data->width);
		data->offset_y = cy - (y - data->height / 2.0) / (0.5 * data->zoom
				* data->height);
		if (data->fractal == 0)
			draw_mandelbrot(data);
		else
			draw_julia(data);
	}
	return (0);
}

void	cleanup_and_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	double	speed;

	speed = 0.1 / data->zoom;
	if (keycode == 65307)
		cleanup_and_exit(data);
	else if (keycode == 65362)
		data->offset_y -= speed;
	else if (keycode == 65364)
		data->offset_y += speed;
	else if (keycode == 65361)
		data->offset_x -= speed;
	else if (keycode == 65363)
		data->offset_x += speed;
	if (data->fractal == 1)
		draw_julia(data);
	else
		draw_mandelbrot(data);
	return (0);
}
