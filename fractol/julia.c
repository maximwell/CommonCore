#include "fractol.h"

int	julia(int x, int y, t_data *data)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = (x - data->width / 2.0) / (0.5 * data->zoom * data->width)
		+ data->offset_x;
	zi = (y - data->height / 2.0) / (0.5 * data->zoom * data->height)
		+ data->offset_y;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < data->max_iter)
	{
		tmp = zr * zr - zi * zi + data->julia_c_re;
		zi = 2 * zr * zi + data->julia_c_im;
		zr = tmp;
		i++;
	}
	if (i == data->max_iter)
		return (0x000000);
	return (0xFFFFFF * i / data->max_iter);
}
