/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:10:40 by youmali           #+#    #+#             */
/*   Updated: 2026/10/16 18:34:48 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	size_t	ls;
	size_t	ld;
	size_t	i;

	ls = ft_strlen((char *)src);
	ld = ft_strlen(dst);
	i = 0;
	if (size <= ld)
		return (ls + size);
	while (src[i] && (ld + i + 1) < size)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ld + ls);
}
