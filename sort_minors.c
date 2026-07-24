/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_minors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:30:58 by blromero          #+#    #+#             */
/*   Updated: 2026/07/24 10:43:12 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->bottom->index;
	if (first > second && first > third && second > third)
	{
		ft_ra(a, bench);
		ft_sa(a, bench);
	}
	else if (first > second && first > third && second < third)
		ft_ra(a, bench);
	else if (first > second && first < third && second < third)
		ft_sa(a, bench);
	else if (first < second && first < third && second > third)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
	else if (first < second && first > third && second > third)
		ft_rra(a, bench);
}

void	ft_sort_minors(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	pos = 0;
	while (a->size > 3)
	{
		pos = ft_min_position(a);
		ft_move_to_top(a, pos, 0, bench);
		ft_pb(a, b, bench);
	}
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			ft_sa(a, bench);
	}
	else
		ft_sort_three(a, bench);
	while (b->size > 0)
		ft_pa(a, b, bench);
}
