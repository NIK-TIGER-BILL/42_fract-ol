/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:58:09 by ebalsami          #+#    #+#             */
/*   Updated: 2021/09/12 15:58:10 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	burning_ship(t_fractol *fractol)
{
	unsigned int	iteration;
	t_complex		z;
	t_complex		tmp_z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	tmp_z = init_complex(z.re * z.re, z.im * z.im);
	while (tmp_z.re + tmp_z.im <= 4
		&& iteration < fractol->max_iteration)
	{
		z.im = -fabs(z.re * z.im);
		z.im += z.im;
		z.im += fractol->c.im;
		z.re = tmp_z.re - tmp_z.im + fractol->c.re;
		tmp_z = init_complex(z.re * z.re, z.im * z.im);
		iteration++;
	}
	return (iteration);
}
