#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && strcmp(argv[1], "mandelbrot") == 0)
	{
		data.fractal     = 0;
		data.zoom        = 1.0;
		data.offset_x    = -0.5;
		data.offset_y    = 0.0;
		data.max_iter    = 50;
		data.julia_c_re  = 0.0;
		data.julia_c_im  = 0.0;
	}
	else if (argc == 4 && strcmp(argv[1], "julia") == 0)
	{
		data.fractal     = 1;
		data.zoom        = 1.0;
		data.offset_x    = 0.0;
		data.offset_y    = 0.0;
		data.max_iter    = 50;
		data.julia_c_re  = atof(argv[2]);
		data.julia_c_im  = atof(argv[3]);
	}
	else
	{
		printf("Usage:\n");
		printf("  ./fractol mandelbrot\n");
		printf("  ./fractol julia <real> <imag>\n");
		return (1);
	}

	data.width = 800;
	data.height = 600;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, data.width, data.height, "fractol");
	if (!data.win)
		return (1);
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	if (!data.img)
		return (1);
	data.addr = mlx_get_data_addr(data.img,
	                              &data.bpp,
	                              &data.line_len,
	                              &data.endian);

	if (data.fractal == 0)
		draw_mandelbrot(&data);
	else
		draw_julia(&data);

	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
