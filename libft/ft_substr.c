/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:41:59 by youmali           #+#    #+#             */
/*   Updated: 2026/10/23 16:37:38 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s);
	if (start >= l)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len > l - start)
		len = l - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memmove(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
