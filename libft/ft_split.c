/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:23:50 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/24 20:23:51 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_memory(char **p)
{
	char	**tmp;

	tmp = p;
	while (*p)
		free(*p++);
	free(tmp);
}

static void	ft_allocate_memory_for_words(char ***p, char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			while (*s != c && *s)
				s++;
			word++;
		}
	}
	(*p) = malloc((word + 1) * sizeof(char *));
	if (*p)
		(*p)[word] = 0;
}

static int	ft_allocate_memory_for_symbols(char ***p, char const *s, char c)
{
	int	word;
	int	symbol;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			symbol = 0;
			while (*s != c && *s)
			{
				symbol++;
				s++;
			}
			(*p)[word] = malloc((symbol + 1) * sizeof(char));
			if (!((*p)[word]))
				return (0);
			word++;
		}
	}
	return (1);
}

static void	ft_pull_data(char ***p, char const *s, char c)
{
	int	word;
	int	symbol;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			symbol = 0;
			while (*s != c && *s)
			{
				(*p)[word][symbol] = *s;
				symbol++;
				s++;
			}
			(*p)[word][symbol] = 0;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char			**p;

	if (!s)
		return (0);
	if (!(*s))
	{
		p = malloc(sizeof (char *));
		if (!p)
			return (0);
		*p = 0;
		return (p);
	}
	ft_allocate_memory_for_words(&p, s, c);
	if (p)
	{
		if (ft_allocate_memory_for_symbols(&p, s, c))
			ft_pull_data(&p, s, c);
		else
		{
			ft_free_memory(p);
			return (0);
		}
	}
	return (p);
}
