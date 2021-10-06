/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:56:20 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:56:21 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;

	if (dst == 0 && src == 0)
		return (0);
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination > source)
		while (len--)
			*(destination + len) = *(source + len);
	else
		while (len--)
			*destination++ = *source++;
	return (dst);
}
