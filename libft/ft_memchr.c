/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:55:55 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:55:56 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	cc;

	source = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n-- > 0)
		if (*source++ == cc)
			return (--source);
	return (0);
}
