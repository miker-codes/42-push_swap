/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:35:48 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/20 16:18:38 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_position(t_stack *stack)
{
	t_node	*tmp;
	int		min_value;
	int		min_pos;
	int		i;

	min_value = stack->top->value;
	tmp = stack->top;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	ft_move_to_top(t_stack *stack, int pos)
{
	int	size;

	size = stack->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ft_ra(stack);
			--pos;
		}
	}
	else
	{
		while (pos < size)
		{
			ft_rra(stack);
			++pos;
		}
	}
}

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 0)
	{
		pos = ft_min_position(a);
		ft_move_to_top(a, pos);
		ft_pb(a, b);
	}
	while (b->size > 0)
		ft_pa(a, b);
}

void	ft_move_to_top_b(t_stack *b, int pos)
{
	int	size;

	size = b->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ft_rb(b);
			--pos;
		}
	}
	else
	{
		while (pos < size)
		{
			ft_rrb(b);
			++pos;
		}
	}
}
