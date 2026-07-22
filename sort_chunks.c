/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:31:19 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 19:49:05 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(int n)
{
	int	chunks;

	chunks = 1;
	while (chunks * chunks < n)
		chunks++;
	return (n / chunks);
}

int	ft_max_position(t_stack *stack)
{
	t_node	*tmp;
	int		max_value;
	int		max_pos;
	int		i;

	tmp = stack->top;
	max_value = tmp->index;
	max_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_value)
		{
			max_value = tmp->index;
			max_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (max_pos);
}

void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_size, t_bench *bench)
{
	int	limit;

	limit = chunk_size;
	while (a->size > 0)
	{
		if (a->top->index < limit)
		{
			ft_pb(a, b, bench);
			if (b->size % chunk_size == 0)
				limit += chunk_size;
		}
		else
			ft_ra(a, bench);
	}
}

void	ft_sort_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk_size;
	int	pos;

	chunk_size = ft_chunk_size(a->size);
	ft_push_chunks(a, b, chunk_size, bench);
	while (b->size > 0)
	{
		pos = ft_max_position(b);
		ft_move_to_top(b, pos, 1, bench);
		ft_pa(a, b, bench);
	}
}
