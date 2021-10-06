/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:57:59 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:58:00 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

static double	interpolate(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	zoom(int button, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		zoom;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(
				(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
				(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
		if (button == MOUSE_SCROLL_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		fractol->min.re = interpolate(mouse.re, fractol->min.re, zoom);
		fractol->min.im = interpolate(mouse.im, fractol->min.im, zoom);
		fractol->max.re = interpolate(mouse.re, fractol->max.re, zoom);
		fractol->max.im = interpolate(mouse.im, fractol->max.im, zoom);
		draw_fractal(fractol);
	}
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->julia_block)
	{
		fractol->k = init_complex(4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
