/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:14:40 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 16:14:41 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		800
# define HEIGHT		800

# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdint.h>

# include <string.h>
# include <inttypes.h>
# include <stdlib.h>

typedef struct s_complex
{
	double			re;
	double			im;
}				t_complex;

typedef struct s_image
{
	 void		*img;
	 char		*addr;
	 int		bits_per_pixel;
	 int		line_length;
	 int		endian;
}				t_image;

typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	t_image			image;
	unsigned int	max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	char			julia_block;
	unsigned char	color_shift;
	double			bright_shift;
	unsigned	int ((*formula)(struct	s_fractol *fractol));
}				t_fractol;

void			set_defaults(t_fractol *fractol);
t_complex		init_complex(double re, double im);
void			my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);

void			draw_fractal(t_fractol *fractol);
void			draw_help(t_fractol *fractol);

unsigned int	mandelbrot(t_fractol *fractol);
unsigned int	julia(t_fractol *fractol);
unsigned int	burning_ship(t_fractol *fractol);

int				get_color(unsigned int iteration, t_fractol *fractol);

int				close_win(void *param);
int				key_press(int key, t_fractol *fractol);
int				zoom(int button, int x, int y, t_fractol *fractol);
int				julia_motion(int x, int y, t_fractol *fractol);

#endif
