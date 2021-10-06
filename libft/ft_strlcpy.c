/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:56:59 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:57:00 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	len;

	if (!dst)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (size-- > 1 && *src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (len);
}
