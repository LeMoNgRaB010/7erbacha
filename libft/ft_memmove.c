/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:54:20 by youmali           #+#    #+#             */
/*   Updated: 2026/10/14 12:17:16 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == dest)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest < src)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else if (dest > src)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
