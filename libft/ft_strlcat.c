/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:54 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 21:04:12 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = (size_t)ft_strlen(dst);
	if (len > dstsize)
		return (dstsize + ft_strlen(src));
	while (*dst && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	len += ft_strlen(src);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (len);
}
