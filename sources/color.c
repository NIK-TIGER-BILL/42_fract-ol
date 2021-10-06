/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:57:48 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:57:49 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(unsigned int iteration, t_fractol *fractol)
{
	double	t;
	int		color;

	if (iteration == fractol->max_iteration)
		return (0);
	t = (double)iteration / fractol->max_iteration;
	if (t != 0)
		t += (1 - t) * fractol->bright_shift;
	color = (unsigned char)(t / ((fractol->color_shift + 0) % 3 + 1) * 255);
	color <<= 8;
	color += (unsigned char)(t / ((fractol->color_shift + 1) % 3 + 1) * 255);
	color <<= 8;
	color += (unsigned char)(t / ((fractol->color_shift + 2) % 3 + 1) * 255);
	return (color);
}
