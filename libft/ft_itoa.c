/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:07:43 by youmali           #+#    #+#             */
/*   Updated: 2026/10/31 15:54:46 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_len(long n)
{
	size_t	l;

	l = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t	l;
	char	*p;
	long	num;

	num = n;
	l = count_len(n);
	p = malloc(l + 1);
	if (!p)
		return (NULL);
	p[l] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		num = -num;
	}
	if (n == 0)
		p[0] = '0';
	while (num > 0)
	{
		p[--l] = num % 10 + '0';
		num = num / 10;
	}
	return (p);
}
