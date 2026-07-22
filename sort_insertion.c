/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 09:47:55 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 19:52:53 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_intruders(t_stack *a, t_stack *b, t_bench *bench)
{
	int	expected;
	int	count;

	expected = 0;
	count = a->size;
	while (count > 0)
	{
		if (a->top->index == expected)
		{
			ft_ra(a, bench);
			expected++;
		}
		else
			ft_pb(a, b, bench);
		count--;
	}
}

int	ft_target_pos_a(t_stack *a, int val)
{
	t_node	*tmp;
	int		pos;

	tmp = a->top;
	pos = 0;
	while (tmp)
	{
		if (val < tmp->index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	ft_sort_insertion(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	ft_push_intruders(a, b, bench);
	while (b->size > 0)
	{
		pos = ft_max_position(b);
		ft_move_to_top(b, pos, 1, bench);
		pos = ft_target_pos_a(a, b->top->index);
		ft_move_to_top(a, pos, 0, bench);
		ft_pa(a, b, bench);
	}
	pos = ft_min_position(a);
	ft_move_to_top(a, pos, 0, bench);
}
