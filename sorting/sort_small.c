/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:44 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 18:37:58 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_data *a)
{
	t_stack	*current;

    if (!a || !a->stack || !a->stack->next)
		return (1);
	current = a->stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_min_position(t_data *stack_a)
{
	t_stack	*i;
	int		min;
	int		index;
	int		pos;

	i = stack_a->stack;
	min = i->value;
	index = 0;
	pos = 0;
	while (i)
	{
		if (min > i->value)
		{
			min = i->value;
			pos = index;
		}
		index++;
		i = i->next;
	}
	return (pos);
}

void	ft_min_to_top(t_data *a)
{
	int		pos;

	pos = ft_min_position(a);
	while (pos--)
		ft_ra(a);
}

void	ft_sort_selection(t_data *stack_a, t_data *stack_b)
{
	if (!stack_a || !stack_b || ft_is_sorted(stack_a))
		return ;
	while (stack_a->size_stack > 0)
	{
		ft_min_to_top(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->size_stack > 0)
		ft_pa(stack_a, stack_b);
}
