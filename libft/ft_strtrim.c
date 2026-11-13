/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:46:13 by youmali           #+#    #+#             */
/*   Updated: 2026/10/18 15:33:00 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!s1 || !set)
		return (NULL);
	l = ft_strlen((char *)s1);
	while (s1[i] && ft_strchr((char *)set, s1[i]))
		i++;
	while (l > i && ft_strrchr((char *)set, s1[l - 1]))
		l--;
	return (ft_substr(s1, i, l - i));
}
