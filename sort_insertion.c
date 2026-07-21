/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 09:47:55 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/21 13:18:48 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_insertion(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 0)
		ft_pb(a, b);
	while (b->size > 0)
	{
		pos = ft_max_position(b);
		ft_move_to_top(b, pos, 1);
		ft_pa(a, b);
	}
}
