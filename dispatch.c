/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:27:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/24 10:39:52 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_strategy(char *arg)
{
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (0);
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		return (2);
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		return (3);
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		return (4);
	return (-1);
}

void	ft_dispatch(t_stack *a, t_stack *b, t_bench *bench, int strategy)
{
	if (strategy == 1)
	{
		bench->complexity = 1;
		if (!ft_is_sorted(a))
			ft_sort_simple(a, b, bench);
	}
	else if (strategy == 2)
	{
		bench->complexity = 2;
		if (!ft_is_sorted(a))
			ft_sort_chunks(a, b, bench);
	}
	else if (strategy == 3)
	{
		bench->complexity = 3;
		if (!ft_is_sorted(a))
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
		if (!ft_is_sorted(a))
			ft_sort_simple(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		bench->complexity = 5;
		ft_sort_chunks(a, b, bench);
	}
	else
	{
		bench->complexity = 6;
		ft_sort_radix(a, b, bench);
	}
}

int	ft_get_flag(char **argv, int *active, int *start)
{
	int	first;
	int	second;

	first = ft_get_strategy(argv[1]);
	if (ft_check_no_flag(first, start))
		return (0);
	second = -1;
	if (argv[2])
		second = ft_get_strategy(argv[2]);
	if (second == -1)
		return (ft_flag_single(first, active, start));
	if ((first == 4 || second == 4) && first != second)
		return (ft_flag_double(first, second, active, start));
	return (-1);
}
