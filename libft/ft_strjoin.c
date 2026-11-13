/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:59:08 by youmali           #+#    #+#             */
/*   Updated: 2026/10/23 16:41:54 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	p = malloc(l1 + l2 + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, l1);
	ft_memmove(p + l1, s2, l2);
	p[l1 + l2] = '\0';
	return (p);
}
