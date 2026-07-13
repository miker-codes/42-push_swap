/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:21:37 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/13 11:29:24 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_top(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
}

void	ft_sa(t_stack *a)
{
	ft_swap_top(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *b)
{
	ft_swap_top(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap_top(a);
	ft_swap_top(b);
	ft_putstr_fd("ss\n", 1);
}
