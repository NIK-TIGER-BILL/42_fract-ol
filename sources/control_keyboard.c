/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keyboard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:57:53 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:57:54 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

static void	move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex(fabs(fractol->max.re - fractol->min.re),
			fabs(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	draw_fractal(fractol);
}

static void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < (unsigned int)
			(fractol->max_iteration * 1.05))
			fractol->max_iteration = (unsigned int)
				(fractol->max_iteration * 1.05);
	}
	if (key == MAIN_PAD_MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (unsigned int)
				(fractol->max_iteration * 0.95);
		else if (fractol->max_iteration > fractol->max_iteration - 1)
			fractol->max_iteration -= 1;
	}
	draw_fractal(fractol);
}

static void	change_color_shift(t_fractol *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	draw_fractal(fractol);
}

static void	change_bright_shift(int key, t_fractol *fractol)
{
	if (key == NUM_PAD_PLUS && fractol->bright_shift < 1)
		fractol->bright_shift += 0.01;
	else if (key == NUM_PAD_MINUS && fractol->bright_shift > 0)
		fractol->bright_shift -= 0.01;
	draw_fractal(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_R)
	{
		set_defaults(fractol);
		draw_fractal(fractol);
	}
	else if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS)
		change_max_iteration(key, fractol);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fractol);
	else if (key == MAIN_PAD_C)
		change_color_shift(fractol);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		change_bright_shift(key, fractol);
	else if (key == MAIN_PAD_SPACE)
		fractol->julia_block = !fractol->julia_block;
	return (0);
}
