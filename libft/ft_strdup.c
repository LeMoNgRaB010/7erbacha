/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:05:33 by youmali           #+#    #+#             */
/*   Updated: 2026/11/05 13:41:43 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s) + 1;
	p = ft_calloc(l, 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, l);
	return (p);
}

#include<stdio.h>
int main(){

	char str[]="test";
	char *s=ft_strdup(str);

	printf("%s\n",s);




 return 0;
}
