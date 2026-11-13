/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:19:00 by youmali           #+#    #+#             */
/*   Updated: 2026/10/31 16:36:26 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while (*ptr == ' ' || (*ptr >= '\t' && *ptr <= '\r'))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		if (n > (9223372036854775807 - (*ptr - '0')) / 10)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		n = n * 10 + *ptr - '0';
		ptr++;
	}
	return (n * sign);
}
