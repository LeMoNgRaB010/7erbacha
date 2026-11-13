/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:12:40 by youmali           #+#    #+#             */
/*   Updated: 2026/10/30 19:58:12 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p = s1;
	p2 = s2;
	while (i < n
		&& p[i] == p2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (p[i] - p2[i]);
}
