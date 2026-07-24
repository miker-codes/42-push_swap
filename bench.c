/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blromero <blromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:32:41 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/23 20:28:38 by blromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_bench(t_bench *bench, t_stack *a, int *active)
{
	int	index;

	index = 0;
	bench->disorder = ft_disorder_index(a);
	bench->active = *active;
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
	if (bench->complexity == 1)
		write(2, "Simple / O(n²)\n", 16);
	else if (bench->complexity == 2)
		write(2, "Medium / O(n√n)\n", 18);
	else if (bench->complexity == 3)
		write(2, "Complex / O(nlog(n))\n", 21);
	else if (bench->complexity == 4)
		write(2, "Adaptive / O(n²)\n", 16);
	else if (bench->complexity == 5)
		write(2, "Adaptive / O(n√n)\n", 20);
	else if (bench->complexity == 6)
		write(2, "Adaptive / O(nlog(n))\n", 22);
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
