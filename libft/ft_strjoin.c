/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:23:35 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:23:37 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (0);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, (ft_strlen(s1) + 1));
	ft_strlcat(p, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (p);
}
