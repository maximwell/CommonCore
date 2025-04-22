#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		width;
	int		height;

	int		fractal;      /* 0 = Mandelbrot, 1 = Julia */
	double	julia_c_re;
	double	julia_c_im;
}	t_data;

/*
** rendering
*/
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);

/*
** fractal computations
*/
int		mandelbrot(int x, int y, t_data *data);
int		julia(int x, int y, t_data *data);

/*
** event hooks
*/
int		mouse_hook(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
void	cleanup_and_exit(t_data *data);

#endif
