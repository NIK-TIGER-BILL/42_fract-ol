/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:56:13 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:56:14 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	if (dst == 0 && src == 0)
		return (0);
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	while (n-- > 0)
		*destination++ = *source++;
	return (dst);
}
