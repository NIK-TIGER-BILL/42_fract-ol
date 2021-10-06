/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:58:12 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/16 15:58:14 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			result = s;
		s++;
	}
	if ((unsigned char)c == 0)
		return (s);
	return (result);
}
