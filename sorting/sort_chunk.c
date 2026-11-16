/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:26 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/16 16:43:24 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_racine(int nb)
{
	int	racine_nb;
	int	i;

	i = 0;
	while (nb)
	{
		if (i * i <= nb)
			racine_nb = i;
		i++;
	}
	return (racine_nb);
}

void	ft_sort_Chunk(t_data *stack_a, t_data *stack_b)
{
	t_stack	*i;
	t_stack	*j;
	int		counter;
	int		racine_input;
	int		chunk;
	int		top_input;
	int		chunk_pos;
	int		limit;
	int		flag;

	// indexing part , db kola wa7d 3ndo l index dyalo
	// O(n^2) walakin ma usina 7ta chi operation
	i = stack_a->stack;
	while (i->next)
	{
		counter = 0;
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				counter++;
			j = j->next;
		}
		i->index = counter;
		i = i->next;
	}
	// now i'm gonna try to do chuks part with racine n
	top_input = stack_a->size_stack;
	racine_input = ft_get_racine(stack_a->size_stack);
	// now push each chunks using index of it
	chunk = 1;
	while (top_input--)
	{
		chunk_pos = racine_input * chunk;
		limit = chunk_pos - racine_input;
		while (chunk_pos >= limit)
		{
			if (stack_a->stack->index <= chunk_pos)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			chunk_pos--;
		}
		chunk++;
	}
	// now all chunks is sorted , we have to sort each chunk alone
	// i'm gonna try to sort each chunk one by one
	// try to get max index to the top and push it to stack_a
	while (stack_b->stack)
	{
		flag = 0;
		if (stack_b->stack->index + 1 == stack_b->size_stack)
		{
			ft_pa(stack_a, stack_b);
			while (flag--)
				ft_rrb(stack_b);
		}
		else
		{
			ft_rb(stack_b);
			flag++;
		}
	}
}
