/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:25:44 by youmali           #+#    #+#             */
/*   Updated: 2026/10/13 20:10:25 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size )
{
	size_t	i;
	size_t	ls;

	i = 0;
	ls = 0;
	while (src[ls])
	{
		ls++;
	}
	if (size == 0)
		return (ls);
	while ((i < size - 1) && src[i] != '\0' )
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ls);
}
