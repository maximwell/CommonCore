#include "fractol.h"

int	mandelbrot(int x, int y, t_data *data)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		iter;

	/* coordonnées complexes du pixel */
	cr  = (x - data->width  / 2.0)
	    / (0.5 * data->zoom * data->width)
	    + data->offset_x;
	ci  = (y - data->height / 2.0)
	    / (0.5 * data->zoom * data->height)
	    + data->offset_y;

	zr  = 0.0;
	zi  = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	iter = 0;

	while (zr2 + zi2 <= 4.0 && iter < data->max_iter)
	{
		zi  = 2.0 * zr * zi + ci;
		zr  = zr2 - zi2 + cr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iter++;
	}

	if (iter == data->max_iter)
		return (0x000000);  /* noir */
	return ((int)(0xFFFFFF * iter / data->max_iter));
}
