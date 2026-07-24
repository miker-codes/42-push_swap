/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:57:35 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/20 15:57:35 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_print(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_free_stack(a);
	ft_free_stack(b);
	if (bench->active)
		ft_print_bench(bench);
}

int	ft_prepare_stack(t_stack *a, char **argv, int strategy, int start)
{
	if (strategy == -1 || !ft_validate_args(argv, start))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!ft_fill_stack(argv, a, start))
	{
		ft_free_stack(a);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_has_duplicates(a))
	{
		ft_free_stack(a);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

void	ft_push_swap(t_stack *a, t_stack *b, t_bench *bench, char **argv)
{
	int	strategy;
	int	start;
	int	active;

	strategy = 0;
	active = 0;
	start = 0;
	strategy = ft_get_flag(argv, &active, &start);
	if (!ft_prepare_stack(a, argv, strategy, start))
		return ;
	ft_init_bench(bench, a, &active);
	ft_normalize(a);
	ft_dispatch(a, b, bench, strategy);
	ft_free_print(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	ft_init_stack(&b);
	ft_push_swap(&a, &b, &bench, argv);
	return (0);
}
