/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:35:48 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 19:46:59 by mruiz-ra         ###   ########.fr       */
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

void	ft_sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	while (a->size > 0)
	{
		pos = ft_min_position(a);
		ft_move_to_top(a, pos, 0, bench);
		ft_pb(a, b, bench);
	}
	while (b->size > 0)
		ft_pa(a, b, bench);
}

void	ft_move_to_top(t_stack *ab, int pos, int flag, t_bench *bench)
{
	int	size;

	size = ab->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			if (flag)
				ft_rb(ab, bench);
			else
				ft_ra(ab, bench);
			--pos;
		}
	}
	else
	{
		while (pos < size)
		{
			if (flag)
				ft_rrb(ab, bench);
			else
				ft_rra(ab, bench);
			++pos;
		}
	}
}
