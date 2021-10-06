/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:56:32 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:56:33 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	x;
	unsigned char	*y;

	x = (unsigned char )c;
	y = (unsigned char *)(b);
	while (len-- > 0)
		*y++ = x;
	return (b);
}
