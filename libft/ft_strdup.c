/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:23:43 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:23:45 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, (ft_strlen(s1) + 1) * sizeof(char));
	return (p);
}
