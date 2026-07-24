/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blromero <blromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:10:04 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/23 20:50:18 by blromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_add_bottom(t_stack *stack, t_node *node)
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
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}

int	ft_fill_stack(char **argv, t_stack *stack, int start)
{
	int		i;
	t_node	*node;

	i = start;
	while (argv[i])
	{
		node = ft_new_node(ft_atoi(argv[i]));
		if (!node)
			return (0);
		ft_add_bottom(stack, node);
		i++;
	}
	return (1);
}

void	ft_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
