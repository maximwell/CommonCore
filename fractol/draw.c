#include "fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			color = mandelbrot(x, y, data);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	draw_julia(t_data *data)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			color = julia(x, y, data);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
