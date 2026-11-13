/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:22:01 by youmali           #+#    #+#             */
/*   Updated: 2026/10/22 16:43:11 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*curr;

	i = 0;
	if (!lst)
		return (0);
	curr = lst;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
