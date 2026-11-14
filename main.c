/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:57:22 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 18:44:40 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_data	*ft_create_empty_stack(void)
{
	t_data	*b;

	b = malloc(sizeof(t_data));
	if (!b)
		return (NULL);
	b->stack = NULL;
	b->size_stack = 0;
	return (b);
}

int	main(int ac, char **av)
{
	t_data	*a;
	t_data	*b;

	a = ft_create_stack(ac, av);
	b = ft_create_empty_stack();
	// ft_display_stack(a);
	ft_sort_selection(a, b);
	ft_display_stack(a);
	ft_free_stack(a);
	return (0);
}
