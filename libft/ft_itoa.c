/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:23:56 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:23:57 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num, int minus)
{
	int	i;

	i = 1;
	num /= 10;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i + minus);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	len = ft_numlen(n, minus);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	p[len] = 0;
	while (--len >= minus)
	{
		p[len] = (char)(ft_abs((n % 10)) + '0');
		n /= 10;
	}
	if (minus)
		p[0] = '-';
	return (p);
}
