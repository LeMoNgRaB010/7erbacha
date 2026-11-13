/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:25:27 by youmali           #+#    #+#             */
/*   Updated: 2026/10/30 18:52:45 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = curr;
	}
}
