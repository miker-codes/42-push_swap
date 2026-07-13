/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:57:56 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/13 12:15:23 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = ft_pop_top(stack);
	ft_add_bottom(stack, node);
}

void	ft_ra(t_stack *a)
{
	ft_rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *b)
{
	ft_rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
