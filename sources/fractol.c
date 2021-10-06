/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:57:41 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:58:35 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	(*get_fractal(char *name)) (t_fractol *fractol)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		return (&mandelbrot);
	else if (!ft_strcmp(name, "Julia"))
		return (&julia);
	else if (!ft_strcmp(name, "Burning Ship"))
		return (&burning_ship);
	else
		return (0);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	if (HEIGHT > WIDTH)
	{
		fractol->max.re = 2.0;
		fractol->max.im = fractol->min.im
			+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	}
	else
	{
		fractol->max.im = 2.0;
		fractol->max.re = fractol->min.re
			+ (fractol->max.im - fractol->min.im) * WIDTH / HEIGHT;
	}
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
	fractol->bright_shift = 0;
}

static void	init_fractol(t_fractol *fractol, char *name)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, name);
	if (!fractol->window)
		exit(-1);
	fractol->image.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image.img)
		exit(-1);
	fractol->image.addr = mlx_get_data_addr(
			fractol->image.img, &(fractol->image.bits_per_pixel),
			&(fractol->image.line_length), &(fractol->image.endian));
	set_defaults(fractol);
	fractol->julia_block = 1;
	fractol->formula = get_fractal(name);
	mlx_hook(fractol->window, 2, 1L << 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close_win, fractol);
	mlx_mouse_hook(fractol->window, zoom, fractol);
	if (!ft_strcmp(name, "Julia"))
		mlx_hook(fractol->window, 6, 1L << 6, julia_motion, fractol);
}

static void	print_names_fractals(void)
{
	ft_putstr_fd("Usage: ./fractol <name>\n\n", 1);
	ft_putstr_fd("Names fractals:\n", 1);
	ft_putstr_fd(" - Mandelbrot\n", 1);
	ft_putstr_fd(" - Julia\n", 1);
	ft_putstr_fd(" - Burning Ship\n", 1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2 && get_fractal(argv[1]))
	{
		init_fractol(&fractol, argv[1]);
		draw_fractal(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		print_names_fractals();
	return (0);
}
