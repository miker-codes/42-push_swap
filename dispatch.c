/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:27:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/21 10:25:21 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_strategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (0);
	return (-1);
}

void	ft_dispatch(t_stack *a, t_stack *b, int strategy)
{
	double	disorder;

	if (ft_is_sorted(a))
		return ;
	if (strategy == 1)
		ft_sort_simple(a, b);
	else if (strategy == 2)
		ft_sort_chunks(a, b);
	else if (strategy == 3)
		ft_sort_radix(a, b);
	else
	{
		disorder = ft_disorder_index(a);
		if (disorder < 0.2)
			ft_sort_insertion(a, b);
		else if (disorder < 0.5)
			ft_sort_chunks(a, b);
		else
			ft_sort_radix(a, b);
	}
}
