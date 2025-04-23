/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:23:38 by mmarhic           #+#    #+#             */
/*   Updated: 2025/04/23 16:23:45 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_data(int argc, char **argv, t_data *data)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal = 0;
		data->zoom = 1.0;
		data->offset_x = -0.5;
		data->offset_y = 0.0;
		data->max_iter = 50;
		data->julia_c_re = 0.0;
		data->julia_c_im = 0.0;
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractal = 1;
		data->zoom = 1.0;
		data->offset_x = 0.0;
		data->offset_y = 0.0;
		data->max_iter = 50;
		data->julia_c_re = ft_atof(argv[2]);
		data->julia_c_im = ft_atof(argv[3]);
	}
	else
		return (0);
	return (1);
}

static int	init_mlx(t_data *data)
{
	data->width = 800;
	data->height = 600;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "fractol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
	return (1);
}

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!init_data(argc, argv, &data))
	{
		print_usage();
		return (1);
	}
	if (!init_mlx(&data))
		return (1);
	if (data.fractal == 0)
		draw_mandelbrot(&data);
	else
		draw_julia(&data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
