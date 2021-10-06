/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:57:06 by ebalsami          #+#    #+#             */
/*   Updated: 2021/04/26 17:57:11 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (*lst)
		{
			temp = *lst;
			*lst = ft_lstlast(*lst);
			(*lst)->next = new;
			*lst = temp;
		}
		else
			*lst = new;
	}
}
