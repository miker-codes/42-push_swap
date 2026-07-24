/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blromero <blromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:21:37 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/23 12:01:57 by blromero         ###   ########.fr       */
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

void	ft_sa(t_stack *a, t_bench *bench)
{
	ft_swap_top(a);
	if (bench->active)
		bench->count[0] += 1;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *b, t_bench *bench)
{
	ft_swap_top(b);
	if (bench->active)
		bench->count[1] += 1;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap_top(a);
	ft_swap_top(b);
	if (bench->active)
		bench->count[2] += 1;
	ft_putstr_fd("ss\n", 1);
}
