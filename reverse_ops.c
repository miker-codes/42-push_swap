/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:08:12 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/13 12:51:40 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	node->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	ft_reverse_rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = ft_pop_bottom(stack);
	ft_add_top(stack, node);
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate_stack(a);
	ft_reverse_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
