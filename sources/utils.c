/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:57:32 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:58:41 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image.addr + (y * fractol->image.line_length + x
			* (fractol->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	close_win(void *param)
{
	(void)param;
	exit(0);
}
