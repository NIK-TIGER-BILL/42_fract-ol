/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:58:04 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:58:05 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *fractol)
{
	int		x;
	int		y;
	int		color;

	fractol->factor = init_complex((
				fractol->max.re - fractol->min.re) / WIDTH,
			(fractol->max.im - fractol->min.im) / HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			my_mlx_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image.img, 0, 0);
}
