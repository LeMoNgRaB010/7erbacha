/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:26 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/16 22:10:52 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_racine(int nb)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return (i);
}

static void	ft_index_stack(t_data *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		counter;

	i = stack->stack;
	while (i)
	{
		counter = 0;
		j = stack->stack;
		while (j)
		{
			if (j->value < i->value)
				counter++;
			j = j->next;
		}
		i->index = counter;
		i = i->next;
	}
}

static void	ft_push_chunk(t_data *a, t_data *b, int start, int end, int target)
{
	int	pushed;

	pushed = 0;
	while (pushed < target)
	{
		if (a->stack->index >= start && a->stack->index < end)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
			ft_ra(a);
	}
}

static void	ft_distribute_chunks(t_data *a, t_data *b, int total)
{
	int	chunk_size;
	int	start;
	int	end;
	int	target;

	chunk_size = ft_get_racine(total);
	start = 0;
	while (start < total)
	{
		end = start + chunk_size;
		if (end > total)
			end = total;
		target = end - start;
		ft_push_chunk(a, b, start, end, target);
		start = end;
	}
}

static int	ft_get_max_pos(t_data *stack)
{
	t_stack	*current;
	int		max;
	int		pos;
	int		max_pos;

	current = stack->stack;
	max = current->index;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	ft_move_max_to_top(t_data *stack)
{
	int	pos;
	int	size;

	size = stack->size_stack;
	pos = ft_get_max_pos(stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_rb(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ft_rrb(stack);
	}
}

static void	ft_rebuild_stack(t_data *a, t_data *b)
{
	while (b->stack)
	{
		ft_move_max_to_top(b);
		ft_pa(a, b);
	}
}

void	ft_sort_chunk(t_data *stack_a, t_data *stack_b)
{
	int	total;

	if (!stack_a || !stack_b || !stack_a->stack)
		return ;
	total = stack_a->size_stack;
	ft_index_stack(stack_a);
	ft_distribute_chunks(stack_a, stack_b, total);
	ft_rebuild_stack(stack_a, stack_b);
}
