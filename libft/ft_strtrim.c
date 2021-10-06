/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:22:33 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:22:34 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(int c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static int	ft_strlenwithoutset(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (ft_isset(*str, set))
		str++;
	if (!*str)
		return (0);
	while (*str++)
		i++;
	while (ft_isset(*(str-- - 2), set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*start;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlenwithoutset(s1, set);
	p = malloc((len + 1) * sizeof (char));
	if (!p)
		return (0);
	while (ft_isset(*s1, set))
		s1++;
	start = p;
	while (*s1 && len-- > 0)
		*p++ = *s1++;
	*p = 0;
	return (start);
}
