/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:49:35 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/19 13:17:14 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = stack->top;
	while (i)
	{
		rank = 0;
		j = stack->top;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

int	ft_count_bits(int size)
{
	int	bits;
	int	max;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	bits;
	int	bit;
	int	i;
	int	size;

	size = a->size;
	bits = ft_count_bits(size);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			i++;
		}
		while (b->size > 0)
			ft_pa(a, b);
		bit++;
	}
}
