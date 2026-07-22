/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:27:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 20:06:05 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_strategy(char *arg, t_bench *bench)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		bench->active = 1;
		return(4);
	}
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (0);
	return (-1);
}

void	ft_dispatch(t_stack *a, t_stack *b, t_bench *bench, int strategy)
{
	if (ft_is_sorted(a))
		return ;
	bench->is_adaptive = 0;
	if (strategy == 0)
		bench->is_adaptive = 1;
	if (strategy == 1)
	{
		bench->complexity = 1;
		ft_sort_simple(a, b, bench);
	}
	else if (strategy == 2)
	{
		bench->complexity = 2;
		ft_sort_chunks(a, b, bench);
	}
	else if (strategy == 3)
	{
		bench->complexity = 3;
		ft_sort_radix(a, b, bench);
	}
	else
		ft_dispatch_adaptive(a, b, bench);
}

void	ft_dispatch_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	double	disorder;

	disorder = ft_disorder_index(a);
	if (disorder < 0.2)
	{
		bench->complexity = 4;
		ft_sort_insertion(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		bench->complexity = 2;
		ft_sort_chunks(a, b, bench);
	}
	else
	{
		bench->complexity = 3;
		ft_sort_radix(a, b, bench);
	}
}
