/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:37:09 by youmali           #+#    #+#             */
/*   Updated: 2026/10/19 16:47:53 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l;
	char	*p;

	i = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen((char *)s) + 1;
	p = malloc(l);
	if (!p)
		return (NULL);
	p[--l] = '\0';
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
