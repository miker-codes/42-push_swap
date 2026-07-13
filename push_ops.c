/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:41:02 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/13 12:59:11 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node	*ft_pop_top(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	node->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = ft_pop_top(a);
	ft_add_top(b, node);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = ft_pop_top(b);
	ft_add_top(a, node);
	ft_putstr_fd("pa\n", 1);
}
