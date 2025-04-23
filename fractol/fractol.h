/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:06:20 by mmarhic           #+#    #+#             */
/*   Updated: 2025/04/23 16:26:07 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Structure principale
*/
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

	int		fractal; /* 0 = Mandelbrot, 1 = Julia */
	double	julia_c_re;
	double	julia_c_im;
}			t_data;

/*
** utils (interdits en extern)
*/
int			ft_strcmp(const char *s1, const char *s2);
double		ft_atof(const char *str);

/*
** rendering
*/
void		draw_mandelbrot(t_data *data);
void		draw_julia(t_data *data);

/*
** fractal computations
*/
int			mandelbrot(int x, int y, t_data *data);
int			julia(int x, int y, t_data *data);

/*
** event hooks
*/
int			mouse_hook(int button, int x, int y, t_data *data);
int			key_hook(int keycode, t_data *data);
void		cleanup_and_exit(t_data *data);

#endif
