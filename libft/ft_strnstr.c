/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:54:37 by youmali           #+#    #+#             */
/*   Updated: 2026/10/16 18:43:02 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	if (!big || !little)
		return (NULL);
	l = ft_strlen((char *)little);
	if (!l)
		return ((char *)big);
	while (len >= l && *big != '\0')
	{
		if (!ft_memcmp(big, little, l))
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}
