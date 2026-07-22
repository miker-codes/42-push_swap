/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:32:41 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 20:27:19 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_bench(t_bench *bench, t_stack *a)
{
	int	index;
	double disorder;

	index = 0;
	bench->disorder = ft_disorder_index(a);
	disorder = ft_disorder_index(a);
	disorder = bench->disorder;
	bench->active = 0;
	while (index < 11)
	{
		bench->count[index] = 0;
		index++;
	}
}

void	ft_print_disorder(double disorder)
{
	int	total;
	int	entero;
	int	decimal;

	total = (int)(disorder * 10000);
	entero = total / 100;
	decimal = total % 100;
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(entero, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
}

void	ft_print_strategy(t_bench *bench)
{
	write(2, "[bench] strategy: ", 18);
	if (bench->is_adaptive)
		write(2, "Adaptive / ", 11);
	else if (bench->complexity == 1)
		write(2, "Simple / ", 9);
	else if (bench->complexity == 2)
		write(2, "Medium / ", 9);
	else if (bench->complexity == 3)
		write(2, "Complex / ", 10);
	if (bench->complexity == 1)
		write(2, "O(n^2)\n", 7);
	else if (bench->complexity == 2)
		write(2, "O(n sqrt n)\n", 12);
	else if (bench->complexity == 3)
		write(2, "O(n log n)\n", 11);
	else if (bench->complexity == 4)
		write(2, "O(n)\n", 5);
}

void	ft_print_bench(t_bench *bench)
{
	ft_print_disorder(bench->disorder);
	ft_print_strategy(bench);
	ft_print_total(bench);
	ft_print_count(bench);
}

void	ft_print_total(t_bench *bench)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (index < 11)
	{
		result += bench->count[index];
		index++;
	}
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(result, 2);
	write(2, "\n", 1);
}
