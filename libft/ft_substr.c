/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:22:25 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:22:26 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		p = malloc(1 * sizeof(char));
		if (!p)
			return (0);
		p[0] = 0;
		return (p);
	}
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, (s + start), len + 1);
	return (p);
}
