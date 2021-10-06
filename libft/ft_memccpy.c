/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:55:46 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:55:47 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	unsigned char	cc;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	cc = (unsigned char)c;
	while (n-- > 0)
	{
		*destination++ = *source;
		if (*source++ == cc)
			return (destination);
	}
	return (0);
}
